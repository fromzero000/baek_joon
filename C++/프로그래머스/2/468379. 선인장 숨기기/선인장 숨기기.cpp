#include <string>
#include <vector>

using namespace std;

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    vector<int> answer{0, 0};
    
    int left = 0, right = drops.size();
    
    auto findSafe = [&](int mid)->vector<int>{
        vector<int> result;
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        for(int i = 0; i < mid; i++) 
        {
            grid[drops[i][0]][drops[i][1]] = 1;
        }
        
        vector<vector<int>> psum(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++) 
                psum[i][j] = grid[i-1][j-1] + psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
        
        for(int i = 0; i <= m-h; i++)
        {
            for(int j = 0; j <= n-w; j++)
            {
                int r1 = i, c1 = j;
                int r2 = i+h, c2 = j+w;
                int rainCnt = psum[r2][c2]-psum[r1][c2]-psum[r2][c1]+psum[r1][c1];
                if(rainCnt == 0)
                {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    };
    
    while(left <= right)
    {
        int mid = (left+right)/2;
        vector<int> result = findSafe(mid);
        if(result[0] != -1)
        {
            answer = result;
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }
    return answer;
}