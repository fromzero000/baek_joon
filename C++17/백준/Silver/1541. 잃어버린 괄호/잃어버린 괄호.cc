#include <bits/stdc++.h>
using namespace std;
int result;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    bool isMinus = 0;
    string temp;
    for(int i = 0; i <= s.length(); i++){
        if(s[i]>='0'&&s[i]<='9'){
            temp += s[i];
            continue;
        }
        if(s[i]=='+'||s[i]=='-'){
            if(isMinus)
                result -= stoi(temp);
            else
                result += stoi(temp);
            temp.clear();
        }
        if(s[i] == '-'){
            isMinus = 1;
            continue;
        }
    }
    if(isMinus)
        result -= stoi(temp);
    else
        result += stoi(temp);
    cout << result;
}