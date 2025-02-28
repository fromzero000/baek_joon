#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int arr[n+5];
    arr[1] = 0;
    for(int i = 2; i <= n; i++){
        arr[i] = arr[i-1]+1;
        if(i%2==0) arr[i] = min(arr[i],arr[i/2]+1);
        if(i%3==0) arr[i] = min(arr[i],arr[i/3]+1);
    }
    cout<<arr[n];
}