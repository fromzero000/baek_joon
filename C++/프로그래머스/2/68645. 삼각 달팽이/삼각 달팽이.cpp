#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    int r = -1, c = 0;
    int num = 1;
    
    for (int i = 0; i < n; i++) 
    {
        for (int j = i; j < n; j++) 
        {
            if (i % 3 == 0) 
            {
                r++;
            }
            else if (i % 3 == 1) 
            {
                c++;
            } 
            else if (i % 3 == 2) 
            {
                r--;
                c--;
            }
            board[r][c] = num++;
        }
    }
    
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j <= i; j++) 
        {
            answer.push_back(board[i][j]);
        }
    }
    
    return answer;
}