#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, age;
    string name;
    vector<pair<int, string>> members;
    cin>>N;
    for(auto i = 0; i < N; i++){
        cin>>age>>name;
        members.push_back({age,name});
    }
    
    stable_sort(members.begin(), members.end(),[](const auto& a, const auto& b){return a.first < b.first;});
    
    for(const auto& mem : members) cout<<mem.first<<' '<<mem.second<<'\n';
}