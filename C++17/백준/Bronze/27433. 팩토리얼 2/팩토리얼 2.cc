#include <iostream>
using namespace std;

int n;
long long func(int k){
    if(k<=1) return 1;
    else return k*func(k-1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    
    cout<<func(n);
}