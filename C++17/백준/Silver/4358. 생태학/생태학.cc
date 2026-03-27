#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    map<string, int> trees;
    string name;
    float total = 0;
    while(getline(cin, name))
    {
        if(trees.find(name)!=trees.end())
            trees[name]++;
        else
            trees[name] = 1;
        total++;
    }
    cout << fixed << setprecision(4);
    for(const auto& [n, k] : trees)
        cout << n << ' ' << k*100/total << '\n';
}