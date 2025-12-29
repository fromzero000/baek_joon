#include <bits/stdc++.h>
using namespace std;

int s[100005];
int pos = -1;
void push(int n){
    s[++pos] = n;
}

int pop(){
    return (pos > -1) ? s[pos--] : -1;
}

int top(){
    return s[pos];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, in, current = 1;
    cin>>N;
    vector<char> results;
    results.push_back('+');

    push(current++);
    while(N--){
        cin >> in;
        if(top() > in){
            cout<<"NO";
            return 0;
        }
        while(top() < in){
            push(current++);
            results.push_back('+');
        }
        if(top() == in){
            pop();
            results.push_back('-');
        }
    }
    for(const char &c : results) cout<<c<<'\n';
}