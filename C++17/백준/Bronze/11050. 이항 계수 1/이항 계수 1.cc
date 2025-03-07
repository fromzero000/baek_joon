#include <bits/stdc++.h>
using namespace std;

int n,k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    int nPk = 1, k_factorial = 1;
    for(int i = n; i >= n-k+1; i--) nPk*=i;
    for(int i = k; i >= 2; i--) k_factorial*=i;
    cout<<nPk/k_factorial;
}