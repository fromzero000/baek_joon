#include <bits/stdc++.h>
using namespace std;


bool valid[1000005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int T, k;
  cin >> T;
  char cmd;
  int param;
  while(T--){
    cin >> k;
    
    priority_queue<pair<int, int>> max_heap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    for(int i = 0; i < k; i++) valid[i] = 0;
    for(int i = 0; i < k; i++){
      cin >> cmd >> param;
      if(cmd=='I'){
        max_heap.push({param,i});
        min_heap.push({param,i});
        valid[i] = 1;
      }
      if(cmd=='D'){
        if(param==1){
          while(!max_heap.empty() && !valid[max_heap.top().second]){
            max_heap.pop();
          }
          if(!max_heap.empty()){
            valid[max_heap.top().second] = 0;
            max_heap.pop();
          }
        }
        else{
          while(!min_heap.empty() && !valid[min_heap.top().second]){
            min_heap.pop();
          }
          if(!min_heap.empty()){
            valid[min_heap.top().second] = 0;
            min_heap.pop();
          }
        }
      }
      
    }
    while(!max_heap.empty() && !valid[max_heap.top().second]){
      max_heap.pop();
    }
    while(!min_heap.empty() && !valid[min_heap.top().second]){
      min_heap.pop();
    }

    if(max_heap.empty() && min_heap.empty()) cout<<"EMPTY\n";
    else cout<<max_heap.top().first<<' '<<min_heap.top().first<<'\n';
  }
  
}