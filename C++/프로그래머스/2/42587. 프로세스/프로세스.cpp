#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    int n = priorities.size();
    priority_queue<int> pq;
    for(int p : priorities)
        pq.push(p);

    vector<bool> completed(n, false);

    int idx = 0;
    while(!pq.empty())
    {
        int cur = pq.top();pq.pop();
        while(true)
        {
            if(priorities[idx] == cur)
            {
                if(idx == location)
                    return answer;
                else
                {
                    completed[idx] = true;
                    idx = (idx+1)%n;
                    answer++;
                    break;
                }
            }
            idx = (idx+1)%n;
        }
    }
    
    return answer;
}