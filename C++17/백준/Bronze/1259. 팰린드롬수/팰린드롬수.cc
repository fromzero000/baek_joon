#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int n){
    int reverse = 0, temp = n;

    while(temp){
        reverse = 10*reverse+temp%10;
        temp /= 10;
    }
    return reverse==n?true:false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin>>n&&n!=0){
        if(isPalindrome(n)) cout<<"yes\n";
        else cout<<"no\n";
    }
}