#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

const int INF = 1e9;
int solution(int x, int y, int n) {
    int answer = -1;
    
    
    auto solve = [&]()->int{
        if(x == y) return 0;
        
        queue<pair<int, int>> q;
        unordered_set<int> visited;
        q.push({y, 0});

        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            
            if(cur.first == x) return cur.second;
            if(cur.first%3 == 0 && cur.first/3 >= x && visited.find(cur.first/3)==visited.end())
            {
                q.push({cur.first/3, cur.second+1});
                visited.insert(cur.first/3);
            }
            if(cur.first%2 == 0 && cur.first/2 >= x && visited.find(cur.first/2)==visited.end())
            {
                q.push({cur.first/2, cur.second+1});
                visited.insert(cur.first/2);
            }
            if(cur.first-n >= x && visited.find(cur.first-n)==visited.end())
            {
                q.push({cur.first-n, cur.second+1});
                visited.insert(cur.first-n);
            }
        }
        return -1;
    };
    return solve();
}