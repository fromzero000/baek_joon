#include <bits/stdc++.h>
using namespace std;

int tree[26][2];

void preorder_travel(int current){
    cout<<static_cast<char>('A'+current);
    if(tree[current][0]!=-1) preorder_travel(tree[current][0]);
    if(tree[current][1]!=-1) preorder_travel(tree[current][1]);
}
void inorder_travel(int current){
    if(tree[current][0]!=-1) inorder_travel(tree[current][0]);
    cout<<static_cast<char>('A'+current);
    if(tree[current][1]!=-1) inorder_travel(tree[current][1]);
}
void postorder_travel(int current){
    if(tree[current][0]!=-1) postorder_travel(tree[current][0]);
    if(tree[current][1]!=-1) postorder_travel(tree[current][1]);
    cout<<static_cast<char>('A'+current);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    cin.ignore();
    string str;
    char p, c1, c2;
    for(int i = 0; i < N; i++){
        getline(cin, str);
        stringstream ss(str);
        ss >> p >> c1 >> c2;
        tree[p-'A'][0] = (c1=='.'?-1:c1-'A');
        tree[p-'A'][1] = (c2=='.'?-1:c2-'A');
    }
    preorder_travel(0);cout<<'\n';
    inorder_travel(0);cout<<'\n';
    postorder_travel(0);cout<<'\n';
}