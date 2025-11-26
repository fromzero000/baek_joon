#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int  n;
    int result = 0;
    int t = 5;
    while(t--){
        cin>>n;
        result += n*n;
    }
    cout<<result%10;
}