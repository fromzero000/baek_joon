#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a[7];int sum = 0, smallest = 99;
    for(int i = 0; i < 7; i++){
        cin>>a[i];
        if(a[i]%2!=0){
            sum+=a[i];
            if(smallest > a[i])
                smallest = a[i];
        }
    }
    if(sum>0)
        cout<<sum<<'\n'<<smallest;
    else
        cout<<-1;
}