#include <bits/stdc++.h>
using namespace std;

struct Cave
{
    map<string, Cave> child{};
};


void tree_r(const Cave& root, int depth)
{
    for(const auto& p : root.child)
    {
        for(int d = 0; d < depth; d++) cout << "--";
        cout << p.first << '\n';
        tree_r(p.second, depth+1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    
    cin >> n;
    
    Cave root{};
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        Cave* cur = &root;
        string next;
        
        for(int j = 0; j < k; j++)
        {
            cin >> next;
            cur = &(cur->child[next]);
        }
    }
    
    tree_r(root, 0);
}