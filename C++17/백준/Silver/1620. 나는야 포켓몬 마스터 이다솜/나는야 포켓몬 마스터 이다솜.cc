#include <bits/stdc++.h>
using namespace std;


map<int, string> pokedexByID;
map<string, int> pokedexByName;
bool isNum(const string &str){
    for(const char & c : str)
        if(c<'0'||c>'9') return false;
    return true;
}
int find_by_name(const string &name){
    return pokedexByName[name];
}

string find_by_id(int id){
    return pokedexByID[id];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, id = 1;
    string name;
    cin >> N >> M;
    while(N--){
        cin >> name;
        pokedexByID.insert({id, name});
        pokedexByName.insert({name, id++});
    }
    while(M--){
        string cmd;
        cin >> cmd;
        if(isNum(cmd)) {
            int id = stoi(cmd);
            cout << find_by_id(id) << '\n';
        }
        else cout << find_by_name(cmd) << '\n';
    }
}