#include <iostream>
using namespace std;
int ds[10];
int main(){
    long a,b,c,d;
    cin>>a>>b>>c;
    d = a*b*c;


    while(d){
        int i = d%10;
        ds[i]++;
        d/=10;
    }
    for(int i = 0; i <10; i++)
        cout<<ds[i]<<'\n';
}