#include <bits/stdc++.h>
using namespace std;

int n;
int arr1[1000005];
int arr2[1000005];
int idx[1000005];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    arr1[0] = -1;
    arr2[0] = 0;
    for(int i = 1; i <= n; i++){
        arr1[i] = arr1[i-1]+1;
        arr2[i] = i-1;
        if(i%2==0&&arr1[i]>arr1[i/2]+1){
            arr1[i] = arr1[i/2]+1;
            arr2[i] = i/2;
        }
        if(i%3==0&&arr1[i]>arr1[i/3]+1){
            arr1[i] = arr1[i/3]+1;
            arr2[i] = i/3;
        }
    }
    cout<<arr1[n]<<'\n';

    while(true){
        cout<<n<<' ';
        if(n==1)break;
        n = arr2[n];
    }
}