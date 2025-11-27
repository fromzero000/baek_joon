#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a,b,temp;
    
    cin>>a>>b;
    if(a>b){
        temp = a;
        a = b;
        b = temp;
    }
    int GCD = a, LCM = b;
    if(a!=1){
        for(auto i = 1; i <= a; i++){
            if(a%i==0&&b%i==0) GCD = i;
        }
        LCM = a/GCD*b;
    }
    cout<<GCD<<'\n'<<LCM;
}