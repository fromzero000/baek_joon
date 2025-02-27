#include <iostream>
using namespace std;

int arr[2000005];
int cnt[2000005];
int n;

void count_sort(){
    int i = 0, idx = 0;
    for(int i = 0; i < n; i++){
        cnt[arr[i]+1000000]++;
    }
    while(idx<=2000000){
        while(cnt[idx]){
            arr[i++] = idx - 1000000;
            cout<<arr[i-1]<<'\n';
            cnt[idx]--;
        }
        idx++;
    }
//    for(int i = 0; i < n; i++){
//        cout<<arr[i]<<'\n';
//    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    count_sort();
//    for(int i = 0; i < n; i++){
//        cout<<arr[i]<<'\n';
//    }
}