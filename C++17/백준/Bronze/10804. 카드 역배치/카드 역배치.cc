#include <bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int cards[20];
    for(int i = 0; i < 20; i++){
        cards[i] = i+1;
    }
    int a,b;
    for(int i = 0; i < 10; i++){
        cin>>a>>b;
        for(int j = a - 1; j <= (a - 1 + b - 1)/2; j++){
            int temp = cards[j];
            cards[j] = cards[b - 1 - (j - a + 1)];
            cards[b - 1 - (j - a + 1)] = temp;
        }
    }
    for(int i = 0; i < 20; i++){
        cout<<cards[i]<<' ';
    }
}