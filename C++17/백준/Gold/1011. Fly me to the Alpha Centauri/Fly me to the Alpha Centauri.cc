#include <bits/stdc++.h>
using namespace std;

int t;
int s, e;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--)
    {
        cin >> s >> e;
        long long dist =  e - s;
        long long maxSpeed = sqrt(dist);
        if(maxSpeed * maxSpeed == dist)
            cout << 2*maxSpeed-1 << '\n';
        else if(dist <= maxSpeed*maxSpeed+maxSpeed)
            cout << 2*maxSpeed << '\n';
        else
            cout << 2*maxSpeed+1 << '\n';
    }
}