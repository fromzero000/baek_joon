#include <bits/stdc++.h>
using namespace std;

long long func(long long a, long long b, long long c){
    if(b==1) return a%c;
    long long answer = func(a,b/2,c);
    answer = answer*answer%c;
    if(b%2==0) return answer;
    return answer*a%c;
}

//a^n * a^n == a^2n

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a,b,c;
    cin>>a>>b>>c;
    cout<<func(a,b,c);
}