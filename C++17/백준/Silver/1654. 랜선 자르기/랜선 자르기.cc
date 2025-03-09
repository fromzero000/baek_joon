#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<int> lans;

bool func(long long length){
    long long cnt = 0;
    for(int i = 0; i < k; i++){
        cnt += lans[i]/length;
    }
    return cnt>=n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>k>>n;
    for(int i = 0; i < k; i++){
        int l;
        cin>>l;
        lans.push_back(l);
    }
    sort(lans.begin(),lans.end());

    long long st = 0, en = lans.back();

    while(st<en){
        long long mid = (st+en+1)/2;
        if(func(mid)){
            st = mid;
        }
        else en = mid-1;
    }
    cout<<st;
}