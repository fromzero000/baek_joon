#include <string>
#include <vector>

using namespace std;

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    int n = info.size();
    
    vector<int> childs[n];
    for(const vector<int>& edge : edges)
        childs[edge[0]].push_back(edge[1]);
    
    auto solve = [&](auto& self, int pos, int sheep, int wolf, vector<int> nextChilds)->void{
        if(info[pos] == 1) wolf++;
        else sheep++;
        if(wolf >= sheep) return;
        answer = max(sheep, answer);
        
        vector<int> newNextChilds;
        
        for(int child : nextChilds)
        {
            if(pos == child) continue;
            newNextChilds.push_back(child);
        }
        
        for(int child : childs[pos])
            newNextChilds.push_back(child);
        
        for(int child : newNextChilds)
            self(self, child, sheep, wolf, newNextChilds);
    };
    solve(solve, 0, 0, 0, {0});
    
    return answer;
}