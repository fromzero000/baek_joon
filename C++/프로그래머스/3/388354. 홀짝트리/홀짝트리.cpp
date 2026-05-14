#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer(2, 0);
    unordered_map<int, vector<int>> forest;
    
    for(const auto& edge : edges)
    {
        int u = edge[0], v = edge[1];
        forest[u].push_back(v);
        forest[v].push_back(u);
    }
    set<int> visited;
    for(int i = 0; i < nodes.size(); i++)
    {
        if(visited.find(nodes[i]) != visited.end()) continue;
        visited.insert(nodes[i]);
        vector<int> tree(1, nodes[i]);
        queue<int> q;
        q.push(nodes[i]);
        while(!q.empty())
        {
            int cur = q.front();q.pop();
            for(int next : forest[cur])
            {
                if(visited.find(next) != visited.end()) continue;
                tree.push_back(next);
                visited.insert(next);
                q.push(next);
            }
        }
        int OddEvenRoot = 0, ROddEvenRoot = 0;
        for(int node : tree)
        {
            if(node%2==forest[node].size()%2) OddEvenRoot++;
            else ROddEvenRoot++;
        }
        if(OddEvenRoot == 1) answer[0]++;
        if(ROddEvenRoot == 1) answer[1]++;
    }
    return answer;
}