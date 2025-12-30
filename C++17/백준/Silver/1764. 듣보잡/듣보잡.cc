#include <bits/stdc++.h>
using namespace std;

set<string> d;

void printDBJ(const vector<string> &dbj){
    cout<<dbj.size()<<'\n';
    for(const string& man : dbj)
        cout<<man<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    string name;
    vector<string> dbj;
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        cin >> name;
        d.insert(name);
    }
    for(int i = 0; i < M; i++){
        cin >> name;
        if(d.count(name)){
            dbj.push_back(name);
        }
    }
    sort(dbj.begin(), dbj.end());
    printDBJ(dbj);
}