#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<pair<long long, long long>> p;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }
    long long result = 0;
    for(int i = 0; i < p.size(); i++)
    {
        result += p[i].first*p[(i+1)%n].second - p[(i+1)%n].first*p[i].second;
    }
    cout << fixed << setprecision(1);
    cout << fabs(result)/2;
}