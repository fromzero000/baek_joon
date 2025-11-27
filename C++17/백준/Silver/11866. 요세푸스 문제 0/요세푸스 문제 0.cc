#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,K;
    cin>>N>>K;
    
    queue<int> q1,q2;
    for(int i = 1; i <= N; i++){
        q1.push(i);
    }
    while(q1.size()!=0){
        for(int i = 1; i < K; i++){
            q1.push(q1.front());
            q1.pop();
        }
        q2.push(q1.front());
        q1.pop();
    }
    cout<<'<';
    while(q2.size()!=1){
        cout<<q2.front()<<", ";
        q2.pop();
    }
    cout<<q2.front()<<'>';
}