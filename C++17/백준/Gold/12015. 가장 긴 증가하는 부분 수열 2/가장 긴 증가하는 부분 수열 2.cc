#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> tails;
    tails.push_back(a[0]);
    for(int i = 1; i < n; i++)
    {
        if(a[i] > tails.back())
            tails.push_back(a[i]);
        else
        {
            int l = 0, r = tails.size()-1;
            while(l <= r)
            {
                int mid = (l+r)/2;
                if(tails[mid] < a[i])
                    l = mid+1;
                else
                    r = mid-1;
            }
            tails[l] = a[i];
        }
    }
    cout << tails.size();
}