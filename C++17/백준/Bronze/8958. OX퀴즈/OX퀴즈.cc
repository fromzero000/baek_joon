#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string OX;
    int tc;
    cin>>tc;
    
    while(tc--){
        cin>>OX;
        int O = 0;
        int point = 0;
        for(auto c : OX){
            if(c == 'O'){
                O++;
                point += O;
            }
            else O = 0;
        }
        cout<<point <<'\n';
    }
}