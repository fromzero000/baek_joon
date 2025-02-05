#include <bits/stdc++.h>
using namespace std;

const int MX = 30;
char dat[MX];
int pos = 0;

void push(char c){
    dat[pos++] = c;
}

void pop(){
    pos--;
}
bool empty(){
    return pos==0;
}
char top(){
    return dat[pos - 1];
}
int main(){
    string init;char last;
    int answer = 0,brackets = 0, parentheses = 0, temp = 1;
    cin>>init;
    for(char c : init){
        if(c=='('){
            temp*=2;
            push(c);
        }
        else if(c=='['){
            temp*=3;
            push(c);
        }
        else if(c==')'){
            if(top()!='('||empty()){
                answer = 0; break;
            }
            if(last=='('){
                answer+=temp;
            }
            temp/=2;
            pop();
        }
        else if(c==']'){
            if(top()!='['||empty()){
                answer = 0; break;
            }
            if(last=='['){
                answer+=temp;
            }
            temp/=3;
            pop();
        }
        last = c;
    }
    if(!empty()) answer = 0;
    cout<<answer;
}