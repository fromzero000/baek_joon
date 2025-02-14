#include <bits/stdc++.h>
using namespace std;
int pow(int k){
    if(k==0) return 1;
    return 2*pow(k-1);
}
void hanoi(int a, int b,int k){
    if(k==1){
        cout<<a<<' '<<b<<'\n';
    }
    else{
        hanoi(a,6-a-b,k-1);
        cout<<a<<' '<<b<<'\n';
        hanoi(6-a-b,b,k-1);
    }
        
}
int main(){
    int k;
    cin>>k;
    cout<<pow(k)-1<<'\n';
    hanoi(1,3,k);
}