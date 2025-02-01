#include <iostream>
using namespace std;

bool function(int n){
    if(n<100)
        return true;
    else{
        int term = n%10 - n/10%10;
        while(n/10){
            if(n%10 - n/10%10 == term){
                n/=10;
            }
            else
                return false;
        }
        return true;
    }
}

int main(){
    int n, answer = 0;
    cin>>n;
    for(int i = 1; i <= n; i++){
        if(function(i))
            answer++;
    }
    cout<<answer;
}