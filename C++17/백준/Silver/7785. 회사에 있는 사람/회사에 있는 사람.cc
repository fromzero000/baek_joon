#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    map<string, int> mp;
    int n;
    string name, log;
    cin>>n;
    while(n--){
        cin>>name>>log;
        mp[name] = (log=="enter")?1:0;
    }
    for (auto it = mp.crbegin(); it != mp.crend(); ++it)
        if(it->second==1) std::cout <<it->first <<'\n';
}