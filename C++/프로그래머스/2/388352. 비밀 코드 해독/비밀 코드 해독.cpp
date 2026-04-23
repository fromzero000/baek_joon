#include <string>
#include <vector>

using namespace std;

int count(const vector<int>& a, const vector<int>& b)
{
    int result = 0;
    for(int i : a)
        for(int j : b)
            if(i == j) result++;
    return result;
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    for(int i = 1; i <= n-4; i++)
    {
        for(int j = i+1; j <= n-3; j++)
        {
            for(int k = j+1; k <= n-2; k++)
            {
                for(int l = k+1; l <= n-1; l++)
                {
                    for(int m = l+1; m <= n; m++)
                    {
                        vector cur = {i, j, k, l, m};
                        bool valid = true;
                        for(int idx = 0; idx < q.size(); idx++)
                        {
                            if(count(q[idx], cur) != ans[idx])
                            {
                                valid = false;
                                break;
                            }
                        }
                        if(valid) answer++;
                    }
                }
            }
        }
    }
    return answer;
}