#include <bits/stdc++.h>
using namespace std;

int arr[10001];
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){
        int k;
        cin>>k;
        arr[k]++;
    }
    for(int i = 1; i <10001; i++){
        while(arr[i]--){
            cout<<i<<'\n';
        }
    }
    
}