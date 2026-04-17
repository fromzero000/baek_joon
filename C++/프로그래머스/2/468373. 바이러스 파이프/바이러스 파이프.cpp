#include <bits/stdc++.h>
using namespace std;

int solution(int n, int infection, vector<vector<int>> edges, int k) 
{
    int result = 1;
    vector<bool> infected(n+1, false);
    infected[infection] = true;
    vector<pair<int, int>> pipes[4];
    vector<vector<pair<int, int>>> conn(n+1, vector<pair<int, int>>());
    for(int i = 0; i < n-1; i++)
    {
        pipes[edges[i][2]].push_back({edges[i][0], edges[i][1]});
        conn[edges[i][0]].push_back({edges[i][2], edges[i][1]});
        conn[edges[i][1]].push_back({edges[i][2], edges[i][0]});
    }

    auto solve = [&](auto& self, int pipe, int k, vector<bool> infected) -> void{
        if(k == 0)
        {
            int infectedNum = 0;
            for(bool i : infected)
                if(i) infectedNum++;
            result = max(result, infectedNum);
            return;
        }
        
        queue<int> q;
        for(int i = 1; i <= n; i++)
            if(infected[i]) q.push(i);
        
        while(!q.empty())
        {
            auto cur = q.front();q.pop();
            for(const auto& next : conn[cur])
            {
                if(next.first == pipe && !infected[next.second])
                {
                    q.push(next.second);
                    infected[next.second] = true;
                }
            }
        }
        
        for(int i = 1; i <= 3; i++)
        {
            self(self, i, k-1, infected);
        }
    };
    solve(solve, 1, k, infected);
    solve(solve, 2, k, infected);
    solve(solve, 3, k, infected);
    return result;
}