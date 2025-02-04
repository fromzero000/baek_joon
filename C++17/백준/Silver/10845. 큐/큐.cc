#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int head, tail;

void push(int n){
    dat[tail++] = n;
}

void front(){
    cout<<(tail - head ? dat[head] : -1)<<'\n';
}
void back(){
    cout<<(tail - head ? dat[tail - 1] : -1)<<'\n';
}
void pop(){
    front();
    head++;
}
int size(){
    return tail - head;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin>>N;
    while(N--){
        string op;
        cin>>op;
        if(op=="push"){
            int n;
            cin>>n;
            push(n);
        }else if(op=="pop"){
            if(size()!=0){
                pop();
            }
            else
                cout<<-1<<'\n';
        }else if(op=="size")
            cout<<size()<<'\n';
        else if(op=="empty")
            cout<<(size()==0?1:0)<<'\n';
        else if(op=="front")
            front();
        else
            back();
    }
}