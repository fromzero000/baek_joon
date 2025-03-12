#include <bits/stdc++.h>
using namespace std;

int n,k;

int man[6];
int woman[6];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        int s, g;
        cin>>s>>g;
        if(s){
            man[g-1]++;
        }
        else
            woman[g-1]++;
    }
    int answer = 0;
    for(int i= 0; i < 6; i++){
        answer+=(man[i]+k-1)/k;
        answer+=(woman[i]+k-1)/k;
    }
    cout<<answer;
}