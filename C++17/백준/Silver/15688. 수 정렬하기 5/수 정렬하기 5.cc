#include <iostream>
using namespace std;

int cnt[2000005];
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){
        int k;
        cin>>k;
        cnt[k+1000000]++;
    }
    for(int i = 0; i < 2000001; i++){
        while(cnt[i]--){
            cout<<i-1000000<<'\n';
        }
    }
}