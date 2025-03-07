#include <bits/stdc++.h>
using namespace std;

void primeprint(int n, int m){
    vector<bool> is_prime(m+1,1);
    is_prime[1] = false;
    for(int i = 2; i*i <= m; i++){
        for(int j = i*i; j <= m; j+=i){
            is_prime[j] = 0;
        }
    }
    for(int i = n; i <= m; i++){
        if(is_prime[i]) cout<<i<<'\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    primeprint(n,m);
}