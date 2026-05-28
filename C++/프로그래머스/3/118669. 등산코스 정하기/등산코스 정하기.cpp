#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9; // 무한대 값

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<bool> isSummit(n + 1, false);

    for (auto& p : paths) 
    {
        int u = p[0], v = p[1], w = p[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    sort(summits.begin(), summits.end());
    for (int summit : summits) 
        isSummit[summit] = true;
    

    vector<int> intensity(n + 1, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int gate : gates) 
    {
        intensity[gate] = 0;
        pq.push({0, gate});
    }

    while (!pq.empty()) 
    {
        int currW = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

        if (currW > intensity[currNode]) continue;

        if (isSummit[currNode]) continue;
        
        for (auto& edge : adj[currNode]) 
        {
            int nextNode = edge.first;
            int nextW = edge.second;
            
            int maxIntensity = max(currW, nextW);

            if (maxIntensity < intensity[nextNode]) {
                intensity[nextNode] = maxIntensity;
                pq.push({maxIntensity, nextNode});
            }
        }
    }
    
    int minIntensity = INF;
    int bestSummit = -1;
    
    for (int summit : summits) {
        if (intensity[summit] < minIntensity) {
            minIntensity = intensity[summit];
            bestSummit = summit;
        }
    }
    
    return {bestSummit, minIntensity};
}