#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    int n = board.size();
    int m = board[0].size();
    
    vector<vector<int>> sum(n+1, vector<int>(m+1, 0));
    
    for (const vector<int>& sk : skill)
    {
        int type = sk[0], r1 = sk[1], c1 = sk[2], r2 = sk[3], c2 = sk[4];
        int degree = (type == 2)?sk[5]:-sk[5];
        
        //sum 배열에는 업데이트해야 할 수치만 끝점에 기록하고 
        //나중에 왼->오, 위->아래 쓸어내리면서 sum 정산하고 board에 더함
        
        sum[r1][c1] += degree;
        sum[r1][c2+1] -= degree;
        sum[r2+1][c1] -= degree;
        sum[r2+1][c2+1] += degree;
    }
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            sum[i][j+1] += sum[i][j];
    
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            sum[j+1][i] += sum[j][i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            board[i][j] += sum[i][j];
            if(board[i][j] > 0) answer++;
        }
    
    return answer;
}