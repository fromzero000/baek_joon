#include <bits/stdc++.h>
using namespace std;
int t,m,n,x,y,l;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>t;

    while(t--){
        cin>>m>>n>>x>>y;
        bool nfind = 1;
        if(x==m) x = 0;
        if(y==n) y = 0;
        l = lcm(m,n);
        for(int i = x; i <= l; i+=m){
            if(i==0) continue;
            if(i%n==y) {
                cout << i << '\n';
                nfind = 0;
                break;
            }
        }
        if(nfind) cout<<-1<<'\n';
    }
}
