#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//화살 동수(0 제외) => 어피치 승
//if 라이언이 최종 점수가 더 높으면 가장 높은 점수일 때 맞춘 화살 개수
//else -1
vector<int> solution(int n, vector<int> info) {
    vector<int> answer{-1};
    vector<int> temp(11);
    reverse(info.begin(), info.end());
    int highest = 0;
    auto solve = [&](auto& self, int cur, int rest, int apeach, int lion)->void{
        if(rest == 0)
        {
            for(int i = cur; i < 11; i++)
                apeach += (info[i]?i:0);
            if(lion <= apeach) return;
            if(lion-apeach > highest)
            {
                highest = lion-apeach;
                answer = temp;
            }
            return;
        }
        if(cur == 11) 
        {
            if(apeach >= lion) return;
            if(highest < lion-apeach) 
            {
                highest = lion-apeach;
                answer = temp;
                return;
            }
            return;
        }
        for(int i = rest; i >= 0; i--)
        {
            if(info[cur] >= i && info[cur] > 0)
                apeach += cur;
            else if(i > 0) 
                lion += cur;
            temp[cur] = i;
            self(self, cur+1, rest-i, apeach, lion);
            temp[cur] = 0;
            if(info[cur] >= i && info[cur] > 0)
                apeach -= cur;
            else if(i > 0) 
                lion -= cur;
        }
    };
    
    solve(solve, 0, n, 0, 0);
    reverse(answer.begin(), answer.end());
    return answer;
}