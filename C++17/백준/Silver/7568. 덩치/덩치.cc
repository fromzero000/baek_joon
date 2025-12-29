#include <bits/stdc++.h>
using namespace std;

bool isBigger(const pair<int, int> a, pair<int, int> b){
    return a.first>b.first && a.second>b.second;
}

pair<int, int> members[50];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, w, h;
    cin >> N;
    vector<int> ratings(N, 0);
    for(int i = 0; i < N; i++){
        cin >>w>>h;
        members[i] = {w, h};
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(isBigger(members[j],members[i])){
                ratings[i]++;
            }
        }
    }
    for(const int& rating : ratings){
        cout<<rating+1<<' ';
    }
}