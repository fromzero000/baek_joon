#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;cin>>N;
    int five = 0, two = 0;
    while(N){
        int temp = N;
        if(temp==0) break;
        while(temp%5==0) {
            five++;
            temp/=5;
        }
        while(temp%2==0) {
            two++;
            temp/=2;
        }
        N--;
    }
    cout<<(five<two?five:two);
}