#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[2*MX+1];
int head = MX, tail = MX;
void push_front(int n){
    dat[--head] = n;
}
void push_back(int n){
    dat[tail++] = n;
}

int front(){
    return dat[head];
}
int back(){
    return dat[tail - 1];
}
void pop_front(){
    head++;
}
void pop_back(){
    tail--;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    while(N--){
        string op;
        cin>>op;
        if(op=="push_front"){
            int n;
            cin>>n;
            push_front(n);
        }
        else if(op=="push_back"){
            int n;
            cin>>n;
            push_back(n);
        }
        else if(op=="pop_front"){
            if(tail - head > 0){
                cout<<front()<<'\n';
                pop_front();
            }else
                cout<<-1<<'\n';
        }
        else if(op=="pop_back"){
            if(tail - head > 0){
                cout<<back()<<'\n';
                pop_back();
            }else
                cout<<-1<<'\n';
        }
        else if(op=="size")
            cout<<tail - head<<'\n';
        else if(op=="empty")
            cout<<(tail==head ? 1 : 0)<<'\n';
        else if(op=="front")
            cout<<(tail - head > 0 ? front() : -1)<<'\n';
        else
            cout<<(tail - head > 0 ? back() : -1)<<'\n';
    }
}