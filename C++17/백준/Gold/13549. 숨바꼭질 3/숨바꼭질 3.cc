#include <bits/stdc++.h>
using namespace std;

int N, K;

deque<int> deq;
int timestamp[100001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
    
    fill(timestamp, timestamp+100001, -1);
    timestamp[N] = 0;
    deq.push_back(N);
    while(!deq.empty()){
        int current = deq.front();
        deq.pop_front();
        
        if(current==K){
            cout << timestamp[K];
            return 0;
        }
        if(current <= 50000 && timestamp[current * 2] == -1){
            timestamp[current * 2] = timestamp[current];
            deq.push_front(current * 2);
        }
        if(current >= 1 && timestamp[current - 1] == -1){
            timestamp[current - 1] = timestamp[current] + 1;
            deq.push_back(current - 1);
        }
        if(current <= 99999 && timestamp[current + 1] == -1){
            timestamp[current + 1] = timestamp[current] + 1;
            deq.push_back(current + 1);
        }
        
    }
}