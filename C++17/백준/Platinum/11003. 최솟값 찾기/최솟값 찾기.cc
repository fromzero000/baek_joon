#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    deque<pair<int, int>> dq;
    int N, L;
    cin>>N>>L;
    vector<int> vec(N);

    for(auto i = 0; i < N; i++){
        cin>>vec[i];
        
        if(!dq.empty()&&dq.front().second<i-L+1) dq.pop_front();
        while(!dq.empty()&&dq.back().first>=vec[i]) dq.pop_back();
        dq.push_back({vec[i],i});
        cout<<dq.front().first<<' ';
    }
    
}