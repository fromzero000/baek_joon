#include <bits/stdc++.h>
using namespace std;

int n,k,answer;
int coin[11];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>coin[i];
    int c = n-1;
    while(k){
        if(k/coin[c]==0){
            c--;
        }
        answer+=k/coin[c];
        k%=coin[c];
    }
    cout<<answer;
}