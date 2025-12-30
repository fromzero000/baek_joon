#include <bits/stdc++.h>
using namespace std;

int heap[100001];
int sz = 0;
int top(){
    return heap[1];
}
void push(int n){
    heap[++sz] = n;
    int idx = sz;
    while(idx!=1){
        if(heap[idx/2] > heap[idx]) swap(heap[idx/2], heap[idx]);
        else break;
        idx /= 2;
    }
}
void pop(){
    heap[1] = heap[sz--];
    int idx = 1;
    while(2*idx<=sz){
        int l = idx*2, r = idx*2+1;
        int min_child = l;
        if(r<=sz && heap[l] > heap[r]) min_child = r;
        if(heap[idx] <= heap[min_child]) break;
        swap(heap[idx], heap[min_child]);
        idx = min_child;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, cmd;
    cin >> N;
    
    while(N--){
        cin >> cmd;
        if(cmd==0) {
            if(sz==0) {
              cout<<0<<'\n';
              continue;
            }
            cout<<top()<<'\n';
            pop();
        }
        else{
            push(cmd);
        }
    }
}