#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    sort(mats.begin(), mats.end(), [](int a, int b){return a > b;});
    
    int n = park.size();
    int m = park[0].size();

    for(int mat : mats)
    {
        for(int i = 0;i <= n-mat; i++)
        {
            for(int j = 0; j <= m-mat; j++)
            {
                if(park[i][j] == "-1")
                {
                    int possible = true;
                    for(int r = i; r < i+mat; r++)
                    {
                        for(int c = j; c < j+mat; c++)
                        {
                            if(park[r][c] != "-1")
                            {
                                possible = false;
                                break;
                            }
                        }
                        if(!possible) break;
                    }
                    if(possible) return mat;                    
                }
            }
        }
    }
    return answer;
}