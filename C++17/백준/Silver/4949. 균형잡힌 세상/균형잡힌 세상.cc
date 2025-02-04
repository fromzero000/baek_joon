#include <bits/stdc++.h>
using namespace std;

int mx = 100;
char stk[100];
int pos = 0;
void push(char c){
    stk[pos++] = c;
}
char top(){
    return stk[pos-1];
}
void pop(){
    pos--;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    getline(cin, str);

    while(true){
        if(str==".")
            break;
        string answer = "yes";
        for(char c : str){
            if(c=='['){
                push(c);
            }
            else if(c=='('){
                push(c);
            }
            else if(c==']'){
                if(pos==0||top()!='['){
                    answer = "no";
                    pos = 0;
                    break;
                }
                else pop();
            }
            else if(c==')'){
                if(pos==0||top()!='('){
                    answer = "no";
                    pos = 0;
                    break;
                }
                else pop();
            }
            else if(c=='.')
                break;
        }
        if(top()=='['||top()=='(') answer = "no";
        cout<<answer<<'\n';
        getline(cin,str);
        pos = 0;
    }
}