#include <bits/stdc++.h>
using namespace std;
#define row first
#define col second
int city[51][51];
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
int not_closed_down[13];
int n,m;
unsigned long long answer;
void func(int k, int idx){
    if(k==m){
        unsigned long long total = 0;
        for(int i = 0; i < home.size(); i++){
            int distance = (n-1)*2;
            for(int j = 0; j < m; j++){
                distance = min(distance, abs(chicken[not_closed_down[j]].row - home[i].row)
                                         +abs(chicken[not_closed_down[j]].col - home[i].col));
            }
            total+=distance;
        }
        answer = min(answer, total);
        return;
    }
    for(int i = idx; m-k<=chicken.size()-i; i++){
        not_closed_down[k] = i;
        func(k+1,i+1);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>city[i][j];
            if(city[i][j]==1){
                home.emplace_back(i,j);
            }
            if(city[i][j]==2){
                chicken.emplace_back(i,j);
            }
        }
    }
    answer = home.size()*(n-1)*(n-1);

    func(0,0);
    cout<<answer;
}