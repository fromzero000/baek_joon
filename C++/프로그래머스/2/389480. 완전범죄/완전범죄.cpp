#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    vector<vector<int>> A_take(info.size()+1,vector<int>(m,120));
    int answer = 120;
    A_take[0][0] = 0;
    for(size_t i = 1; i <= info.size(); i++){
        int a = info[i-1][0];
        int b = info[i-1][1];
        
        for(int j = 0; j < m; j++){
            A_take[i][j] = min(A_take[i][j], A_take[i-1][j]+a);
            if(j+b < m) 
                A_take[i][j+b] = min(A_take[i-1][j],A_take[i][j+b]);
        }
    }
    for(int i = 0; i < m; i++){
        answer = min(A_take[info.size()][i], answer);
    }
    if(answer<n) return answer;
    else return -1;
}