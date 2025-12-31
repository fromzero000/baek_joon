#include <bits/stdc++.h>
using namespace std;

bool s[21];

void all(){
    fill(s+1, s+21, 1);
}

void empty(){
    fill(s+1, s+21, 0);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string cmd;int x, N;
    cin >> N;
    while(N--){
        cin >> cmd;
        if(cmd=="add"){
            cin >> x;
            s[x] = 1;
        }
        if(cmd=="remove"){
            cin >> x;
            s[x] = 0;
        }
        if(cmd=="check"){
            cin >> x;
            cout << s[x] <<'\n';
        }
        if(cmd=="toggle"){
            cin >> x;
            s[x] = !s[x];
        }
        if(cmd=="all"){
            all();
        }
        if(cmd=="empty") empty();
    }
}