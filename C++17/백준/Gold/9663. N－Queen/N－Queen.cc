#include <bits/stdc++.h>
using namespace std;

int board[20];
bool is_used[20];bool is_used1[30];bool is_used2[30];
int n;
int answer;
void solve(int k){
    if(k==n){
        answer++;
    }
    for(int i = 1; i <= n; i++){
        if(!is_used[i]){
            board[k] = i;
            if(is_used[i] == 1||is_used1[i+k-1] == 1||is_used2[i-k+n-1] == 1) continue;
            is_used[i] = 1;
            is_used1[i+k-1] = 1;
            is_used2[i-k+n-1] = 1;
            solve(k+1);
            is_used[i] = 0;
            is_used1[i+k-1] = 0;
            is_used2[i-k+n-1] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    
    solve(0);
    cout<<answer;
}