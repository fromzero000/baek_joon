#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int cur;
    Node* left = nullptr;
    Node* right = nullptr;
};

Node* insertNode(Node* node, int data)
{
    if(node == nullptr) return new Node{data};
    
    if(node->cur < data) node->right = insertNode(node->right, data);
    else node -> left = insertNode(node->left, data);
    
    return node;
}


void pot(Node* node)
{
    if(node == nullptr) return;
    pot(node->left);
    pot(node->right);
    cout << node->cur << '\n';
    delete node;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int data;
    
    Node* root = nullptr;
    
    while(cin >> data)
    {
        root = insertNode(root, data);
    }
    pot(root);
}