#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
char dat[MX];
int pre[MX];
int nxt[MX];
int unused = 1;

void insert(int addr, char c){
    dat[unused] = c;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr){
    nxt[pre[addr]] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

void traversal(){
    int init = nxt[0];
    while(init!=-1){
        cout<<dat[init];
        init = nxt[init];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(pre,pre+MX,-1);
    fill(nxt,nxt+MX,-1);
    string str;
    cin>>str;
    int cursor = 0;
    for(char c : str){
        insert(cursor, c);
        cursor++;
    }
    int n;
    cin>>n;
    while(n--){
        char cmd;
        cin>>cmd;
        if(cmd == 'L'){
            if(pre[cursor]!=-1)
                cursor = pre[cursor];
        }
        else if(cmd == 'D'){
            if(nxt[cursor]!=-1)
                cursor = nxt[cursor];
        }
        else if(cmd=='B'){
            if(pre[cursor]!=-1){
                erase(cursor);
                cursor = pre[cursor];
            }
        }
        else{
            char c;
            cin>>c;
            insert(cursor,c);
            cursor = nxt[cursor];
        }
    }
    traversal();
}