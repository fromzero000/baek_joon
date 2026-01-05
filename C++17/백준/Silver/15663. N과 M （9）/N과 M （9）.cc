#include <bits/stdc++.h>
using namespace std;

int N, M;
int nums[8];
int current[8];
int used[8];
void dfs(int idx){
    if(idx == M){
        for(int i = 0; i < M; i++){
            cout<<current[i]<<' ';
        }
        cout<<'\n';return;
    }
    int temp = 0;
    for(int i = 0; i < N; i++){
        if(used[i]) continue;
        if(temp == nums[i]) continue;
        current[idx] = nums[i];
        used[i] = 1;
        temp = nums[i];
        dfs(idx+1);
        used[i] = 0;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++)
        cin >> nums[i];

    sort(nums, nums+N);
    dfs(0);
}