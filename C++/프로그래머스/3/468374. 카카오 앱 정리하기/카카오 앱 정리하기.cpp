#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 각 앱의 위치와 크기 정보를 담을 구조체
struct Block {
    int r, c, s;
    bool exists = false;
};

// 두 블록이 이동 방향에 수직인 축(row 또는 col)을 공유하는지(즉, 충돌 가능한지) 확인
bool share_axis(const Block& b1, const Block& b2, int arrow) {
    if (arrow == 1 || arrow == 3) { // 오른쪽, 왼쪽 이동 시 세로축 공유 확인
        return max(b1.r, b2.r) <= min(b1.r + b1.s - 1, b2.r + b2.s - 1);
    } else { // 아래쪽, 위쪽 이동 시 가로축 공유 확인
        return max(b1.c, b2.c) <= min(b1.c + b1.s - 1, b2.c + b2.s - 1);
    }
}

// 이동 방향을 기준으로 b1의 앞면(Front)과 b2의 뒷면(Back) 사이의 거리를 계산 (Wrap-around 고려)
int get_D(const Block& b1, const Block& b2, int arrow, int N, int M) {
    if (arrow == 1) return (((b2.c - (b1.c + b1.s - 1) - 1) % M) + M) % M;
    if (arrow == 2) return (((b2.r - (b1.r + b1.s - 1) - 1) % N) + N) % N;
    if (arrow == 3) return (((b1.c - (b2.c + b2.s - 1) - 1) % M) + M) % M;
    if (arrow == 4) return (((b1.r - (b2.r + b2.s - 1) - 1) % N) + N) % N;
    return 0;
}

// 블록이 steps 번 밀렸을 때의 최종 위치 반환
pair<int, int> get_new_pos(const Block& b, int steps, int arrow, int N, int M) {
    int curr_r = b.r, curr_c = b.c;
    for (int step = 1; step <= steps; step++) {
        if (arrow == 1) { // Right
            curr_c++;
            if (curr_c + b.s > M) curr_c = 0;
        } else if (arrow == 2) { // Down
            curr_r++;
            if (curr_r + b.s > N) curr_r = 0;
        } else if (arrow == 3) { // Left
            curr_c--;
            if (curr_c < 0) curr_c = M - b.s;
        } else if (arrow == 4) { // Up
            curr_r--;
            if (curr_r < 0) curr_r = N - b.s;
        }
    }
    return {curr_r, curr_c};
}

// 블록이 steps 번 밀렸을 때, 물리적으로 전진한 칸 수를 반환 (반대편으로 넘어갈 땐 크기만큼 점프)
int get_E(const Block& b, int steps, int arrow, int N, int M) {
    int adv = 0;
    int curr_r = b.r, curr_c = b.c;
    for (int step = 1; step <= steps; step++) {
        if (arrow == 1) {
            curr_c++;
            if (curr_c + b.s > M) { curr_c = 0; adv += b.s; }
            else adv++;
        } else if (arrow == 2) {
            curr_r++;
            if (curr_r + b.s > N) { curr_r = 0; adv += b.s; }
            else adv++;
        } else if (arrow == 3) {
            curr_c--;
            if (curr_c < 0) { curr_c = M - b.s; adv += b.s; }
            else adv++;
        } else if (arrow == 4) {
            curr_r--;
            if (curr_r < 0) { curr_r = N - b.s; adv += b.s; }
            else adv++;
        }
    }
    return adv;
}

vector<vector<int>> solution(vector<vector<int>> board, vector<vector<int>> commands) {
    int N = board.size();
    int M = board[0].size();
    Block blocks[105]; // ID 최대값 100을 충분히 커버하는 배열
    int max_id = 0;

    // 1. 초기 맵 파싱 (각 앱의 좌표와 크기 수집)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int id = board[i][j];
            if (id > 0) {
                max_id = max(max_id, id);
                if (!blocks[id].exists) {
                    blocks[id].exists = true;
                    blocks[id].r = i;
                    blocks[id].c = j;
                    int s = 1;
                    // 앱이 정사각형이므로 오른쪽으로 연속된 같은 ID 개수만 세어 크기 산출
                    while (j + s < M && board[i][j + s] == id) s++;
                    blocks[id].s = s;
                }
            }
        }
    }

    // 2. 커맨드 처리
    for (auto& cmd : commands) {
        int target = cmd[0];
        int arrow = cmd[1];

        // 각 블록이 몇 번의 이동 단계를 거쳐야 하는지 기록
        vector<int> d(max_id + 1, 0);
        if (blocks[target].exists) d[target] = 1;

        bool changed = true;
        int safety = 0;
        
        // 이동에 따른 연쇄 충돌(Push) 판정 루프
        while (changed && safety < 2000) {
            changed = false;
            safety++;
            for (int i = 1; i <= max_id; i++) {
                if (!blocks[i].exists) continue;
                for (int j = 1; j <= max_id; j++) {
                    if (!blocks[j].exists || i == j) continue;
                    
                    // 두 블록이 같은 축 선상에 있다면 밀림 판정
                    if (share_axis(blocks[i], blocks[j], arrow)) {
                        int D_ij = get_D(blocks[i], blocks[j], arrow, N, M);
                        int E_i = get_E(blocks[i], d[i], arrow, N, M);
                        int E_j = get_E(blocks[j], d[j], arrow, N, M);

                        // i 블록의 전진 거리가 j 블록과의 초기 거리 + j 블록의 전진 거리보다 크다면 오버랩 발생 (밀림)
                        if (E_i > D_ij + E_j) {
                            while (get_E(blocks[j], d[j], arrow, N, M) < E_i - D_ij) {
                                d[j]++;
                            }
                            changed = true;
                        }
                    }
                }
            }
        }

        // 3. 연산 완료 후 각 블록의 좌표 업데이트
        for (int i = 1; i <= max_id; i++) {
            if (blocks[i].exists && d[i] > 0) {
                pair<int, int> npos = get_new_pos(blocks[i], d[i], arrow, N, M);
                blocks[i].r = npos.first;
                blocks[i].c = npos.second;
            }
        }
    }

    // 4. 최종 board 생성
    vector<vector<int>> answer(N, vector<int>(M, 0));
    for (int id = 1; id <= max_id; id++) {
        if (blocks[id].exists) {
            for (int r = 0; r < blocks[id].s; r++) {
                for (int c = 0; c < blocks[id].s; c++) {
                    answer[blocks[id].r + r][blocks[id].c + c] = id;
                }
            }
        }
    }
    return answer;
}