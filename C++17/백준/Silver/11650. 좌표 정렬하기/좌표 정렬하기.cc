#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b){
    if(a.first==b.first) return a.second < b.second;
    else return a.first < b.first;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    vector<pair<int, int>> coordinates;
    pair<int, int> temp;
    cin>>n;
    while(n--){
        cin>>temp.first>>temp.second;
        coordinates.push_back(temp);
    }
    sort(coordinates.begin(), coordinates.end(), compare);
    for(const auto& coordinate : coordinates) 
        cout<<coordinate.first<<' '<<coordinate.second<<'\n';
}