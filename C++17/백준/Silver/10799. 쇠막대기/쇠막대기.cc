#include <bits/stdc++.h>
using namespace std;

int main(){
    int answer = 0, s = 0;
    string a;char last;
    cin>>a;
    for(char c : a){
        if(c=='(')
            s++;
        if(c==')'){
            if(last=='('){
                answer += --s;
            }
            else{
                answer += 1;
                s--;
            }
        }last = c;
    }
    answer += s;
    cout<<answer;
}
