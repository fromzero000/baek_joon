#include <bits/stdc++.h>
using namespace std;

int N;

int p[1000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> p[i];
    }
    
    sort(p, p+N);int answer = 0;
    for(int i = 1; i <= N; i++){
        answer += i*p[N-i];
    }
    cout<<answer;
}