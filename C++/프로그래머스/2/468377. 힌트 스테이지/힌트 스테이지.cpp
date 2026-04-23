#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    int n = cost.size();
    
    int answer = 1e9;
    
    for(int mask = 0; mask < (1 << n); mask++)
    {
        int localResult = 0;
        vector<int> hints(n);
        for(int stage = 0; stage < hint.size(); stage++)
        {
            if(mask & (1 << stage))
            {
                localResult += hint[stage][0];
                for(int h = 1; h < hint[stage].size(); h++)
                    hints[hint[stage][h]-1]++;
            }
        }
        
        for(int stage = 0; stage < n; stage++)
        {
            int cnt = min(hints[stage], (int)cost[stage].size()-1);
            localResult += cost[stage][cnt];
        }
            answer = min(localResult, answer);
    }
    return answer;
}