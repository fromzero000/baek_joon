#include <bits/stdc++.h>
using namespace std;

int n,answer;

int rope[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++) cin>>rope[i];
    sort(rope,rope+n,[](const int& a, const int& b){return a>b;});
    answer=rope[0];
    for(int i = 1; i < n; i++){
        if(answer<=rope[i]*(i+1)) answer = rope[i]*(i+1);
    }
    cout<<answer;
}