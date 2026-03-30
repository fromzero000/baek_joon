#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    if(k >= n)
    {
        cout << 0;
        return 0;
    }
    
    vector<int> sensors(n);
    for(int i = 0; i < n; i++)
        cin >> sensors[i];
    
    sort(sensors.begin(), sensors.end());
    vector<int> diff(n-1);
    for(int i = 0; i < n-1; i++)
        diff[i] = sensors[i+1] - sensors[i];
    
    sort(diff.begin(), diff.end());
    int result = 0;
    for(int i = 0; i < (n-1) - (k-1); i++)
        result += diff[i];
        
    cout << result;
}