#include <bits/stdc++.h>
using namespace std;

int d[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    fill(d,d+100004,-1);
    queue<int> q;
    q.push(n);
    d[n] = 0;
    while(d[k]==-1){
        int current = q.front();q.pop();
        if(d[current-1]==-1&&current-1>=0&&current-1<100005){
            d[current-1] = d[current]+1;
            q.push(current-1);
        }
        if(d[current+1]==-1&&current+1>=0&&current+1<100005){
            d[current+1] = d[current]+1;
            q.push(current+1);
        }
        if(d[current*2]==-1&&current*2>=0&&current*2<100005){
            d[current*2] = d[current]+1;
            q.push(current*2);
        }
    }
    cout<<d[k];
}