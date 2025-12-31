#include <bits/stdc++.h>
using namespace std;

int trees[1000000];
int N, M;

long long total_trees(long long h){
    long long result = 0;
    for(int i = 0; i < N; i++)
        if(trees[i] > h) result += trees[i]-h;
    return result;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long highest = 0, lowest = 0;

    cin>> N >> M;
    
    for(int i = 0; i < N; i++){
        cin >> trees[i];
        if(trees[i] > highest) highest = trees[i];
    }
    
    while(lowest<highest){
        long long mid = (lowest+highest+1)/2;
        if(total_trees(mid)>=M) lowest = mid;
        else highest = mid -1;
    }
    cout<<lowest;
}