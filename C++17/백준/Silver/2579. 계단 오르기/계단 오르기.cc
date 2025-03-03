#include <bits/stdc++.h>
using namespace std;
int n;
int stairs[305];
int points[305][2];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1; i < n+1; i++) cin>>stairs[i];
    points[1][0] = stairs[1]; points[2][0] = stairs[2]; points[2][1] = stairs[2]+stairs[1];
    for(int i = 3; i < n+1; i++){
        points[i][0] = max(points[i-2][0], points[i-2][1])+stairs[i];
        points[i][1] = points[i-1][0]+stairs[i];
    }
    cout<<max(points[n][0],points[n][1]);
}
