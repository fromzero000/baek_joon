#include <bits/stdc++.h>
using namespace std;
int t,n,answer;

void func(int k){
    if(k>=n){
        if(k==n)
            answer++;
        return;
    }
    func(k+1);
    func(k+2);
    func(k+3);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        func(0);
        cout<<answer<<'\n';
        answer = 0;
    }
}