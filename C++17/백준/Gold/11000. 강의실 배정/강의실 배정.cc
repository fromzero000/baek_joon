#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> schoolTime(n);
    for(int i = 0; i < n; i++)
        cin >> schoolTime[i].first >> schoolTime[i].second;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    sort(schoolTime.begin(), schoolTime.end(), [](const auto& a, const auto& b){return a.first < b.first || (a.first==b.first && a.second < b.second);});
    pq.push(schoolTime[0].second);
    
    for(int i = 1; i < n; i++)
    {
        int cur = pq.top();
        if(schoolTime[i].first >= cur)
            pq.pop();
        pq.push(schoolTime[i].second);
    }
    
    cout << pq.size();
}