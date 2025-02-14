#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    while(a||b||c){
        int mx = max(a,b);
        mx = max(mx,c);
        if(mx*mx*2==a*a+b*b+c*c)
            cout<<"right"<<'\n';
        else cout<<"wrong"<<'\n';
        cin>>a>>b>>c;
    }
}