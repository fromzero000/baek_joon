#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tc, N, M, importance;
    cin >> tc;
    while(tc--){
        cin>>N>>M;
        queue<pair<int, int>> prints;
        priority_queue<int> pq;
        
        for(int i = 0; i < N; i++){
            cin >> importance;
            prints.push({i, importance});
            pq.push(importance);
        }
        int count = 1;
        while(1){
            if(prints.front().second < pq.top()){
                prints.push(prints.front());
                prints.pop();
            }
            else{
                if(prints.front().first == M) break;
                else {
                    prints.pop();
                    pq.pop();
                    count++;
                }
            }
        }
        cout<<count<<'\n';
    }
}