#include <bits/stdc++.h>
using namespace std;

void parseInt(deque<int>& dq, string arr, int n){
    string temp = "";
    if(n==0) return;
    for(auto i = 1; i < arr.size(); i++){
        if(arr[i]==']'||arr[i]==','){
            dq.push_back(stoi(temp));
            temp = "";
        }
        else temp += arr[i];
    }
}
int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T, n;
    string p, arr;
    cin>>T;
    for(auto i = 0; i < T; i++){
        deque<int> dq;
        bool r = false;
        cin>>p>>n>>arr;
        parseInt(dq, arr, n);
        bool d = false;
        for(const auto& c : p){
            if(c=='R') r = !r;
            if(c=='D'){
                if(d=dq.empty()){
                    cout<<"error\n";
                    break;  
                }
                else{
                    if(r) dq.pop_back();
                    else dq.pop_front();
                } 
            }
        }
        if(d) continue;
        cout<<'[';
        if(!dq.empty()){
            if(r) {
            
                for(int i = dq.size()-1; i > 0; i--){
                    cout<<dq[i]<<',';
                }
                cout<<dq.front();
            }
            else{
                for(int i = 0; i < dq.size()-1; i++){
                    cout<<dq[i]<<',';
                }
                cout<<dq.back();
            }
        }
        
        cout<<"]\n";
    }
}