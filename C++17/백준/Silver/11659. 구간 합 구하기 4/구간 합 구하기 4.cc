#include <bits/stdc++.h>
using  namespace std;
int n,m;
int arr[100005];
int sum[100005];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 1; i < n+1; i++){
        cin>>arr[i];
    }
    sum[0] = 0;
    for(int i = 1; i < n+1; i++){
        sum[i] = arr[i]+ sum[i-1];
    }
    int a,b;
    for(int i = 0; i < m; i++){
        cin>>a>>b;
        cout<<sum[b]-sum[a-1]<<'\n';
    }

}