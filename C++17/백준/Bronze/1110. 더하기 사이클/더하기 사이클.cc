#include <bits/stdc++.h>
using namespace std;

int new_number(int n){
    return (n%10+n/10)%10+n%10*10;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, result = 1;
    cin >> N;
    int prev = N;
    while(N!=new_number(prev)) {
        result++;
        prev = new_number(prev);
    }
    cout<<result;
}