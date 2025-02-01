#include <iostream>
using namespace std;

int is_self_number(int d){
    int sum,_d;
    sum = _d = d;
    while(_d){
        sum+=_d%10;
        _d/=10;
    }
    return sum;
}
int main(){
    int n = 10000;
    int self_nums[n+1];
    for(int i = 1;i <= n; i++){
        if(is_self_number(i)<n)
            self_nums[is_self_number(i)]=1;
    }
    for(int i = 1; i < n; i++)
        if(self_nums[i]!=1) cout<<i<<'\n';
}