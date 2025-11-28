#include <bits/stdc++.h>
using namespace std;

int sizes[6];

int count_bundle(int t){
    int result = 0;
    for(const auto& size : sizes){
        result += (size%t==0?size/t:size/t+1);
    }
    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, t, p;
    
    cin>>n;
    for(auto& size : sizes) cin>>size;
    cin>>t>>p;
    
    cout<<count_bundle(t)<<'\n';
    cout<<n/p<<' '<<n%p;
    
}