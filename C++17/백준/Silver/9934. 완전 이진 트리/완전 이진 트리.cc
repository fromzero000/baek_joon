#include <bits/stdc++.h>
using namespace std;


int k;
vector<int> nodes;
vector<int> tree[10];


void inorder(int st, int en, int depth)
{
    if(st > en) return;
    
    int mid = (st+en)/2;
    
    tree[depth].push_back(nodes[mid]);
    inorder(st, mid-1, depth+1);
    inorder(mid+1, en, depth+1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k;
    int n = pow(2, k)-1;
    nodes.resize(n);
    for(int i = 0; i < n; i++)
        cin >> nodes[i];
    
    inorder(0, n-1, 0);
    
    for(const vector<int>& level : tree)
    {
        for(const int& node : level)
            cout << node << ' ';
        cout << '\n';
    }
}