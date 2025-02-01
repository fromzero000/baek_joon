#include <iostream>
using namespace std;

int main(){
    int n,t;
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            cout<<'*';
        }
        for(int k = n - i; k > 0; k--)
            cout<<"  ";
        for(int j = 0; j < i; j++){
            cout<<'*';
        }
        cout<<'\n';
    }
    for(int i = n - 1; i >0; i--){
        for(int j = 0; j < i; j++){
            cout<<'*';
        }
        for(int k = n - i; k > 0; k--)
            cout<<"  ";
        for(int j = 0; j < i; j++){
            cout<<'*';
        }
        cout<<'\n';
    }
}