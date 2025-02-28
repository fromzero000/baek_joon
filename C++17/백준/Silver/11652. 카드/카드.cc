#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    long long arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);

    long long answer = arr[0], curr = arr[0]; int cnt1 = 1, cnt2 = 1;
    for(int i = 1; i < n; i++){
        if(curr==arr[i]){
            cnt2++;
            if(cnt1<cnt2){
                answer = curr;
                cnt1 = cnt2;
            }
        }
        else{
            if(cnt1<cnt2){
                answer = curr;
                cnt1 = cnt2;
            }
            cnt2 = 1;
            curr = arr[i];
        }
    }
    cout<<answer;
}