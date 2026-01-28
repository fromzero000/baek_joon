#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<int> b;
vector<int> c;
vector<int> d;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    d.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    
    
    long long cnt = 0;
    vector<int> ab(n*n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ab[i*n+j] = a[i]+b[j];
        }
    }
    sort(ab.begin(), ab.end());
    vector<int> cd(n*n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cd[i*n+j] = c[i]+d[j];
        }
    }
    sort(cd.begin(), cd.end());
    for(int i = 0; i < n*n; i++)
    {
        int target = -ab[i];
        cnt += upper_bound(cd.begin(), cd.end(), target)
            - lower_bound(cd.begin(), cd.end(), target);
    }
    
    cout << cnt;
}