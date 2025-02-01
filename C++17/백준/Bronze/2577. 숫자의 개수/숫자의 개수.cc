#include <iostream>
using namespace std;

int main(){
    long a,b,c,d;
    cin>>a>>b>>c;
    d = a*b*c;
    int ds[10];
    for(int i = 0; i < 10; i++)
        ds[i] = 0;
    while(d){
        int i = d%10;
        ds[i]++;
        d/=10;
    }
    for(int i = 0; i <10; i++)
        cout<<ds[i]<<'\n';
}