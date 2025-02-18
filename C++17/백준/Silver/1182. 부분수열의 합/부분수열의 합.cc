#include <bits/stdc++.h>
using namespace std;

int n,s;
int nums[20];
int answer;
void func(int k, int curr){
    if(k==n){
        if(curr==s)
            answer++;
        return;
    } 
    func(k+1,curr);
    func(k+1,curr+nums[k]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int i = 0; i < n; i++)
        cin>>nums[i];
    func(0,0);
    if(s==0) answer--;
    cout<<answer;
}