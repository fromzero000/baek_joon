#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    string PS;
    while(n--){
        cin>>PS;
        int count = 0;
        for(const auto& p :  PS){
            if(p=='(') count++;
            else count--;
            if(count<0) break;
        }
        cout<<(count==0?"YES":"NO");
        cout<<'\n';
    }
}