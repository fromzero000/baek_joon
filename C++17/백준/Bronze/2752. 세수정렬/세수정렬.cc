#include <iostream>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a>=b&&b>=c)
        cout<<c<<' '<<b<<' '<<a;
    else if(a>=c&&b<=c)
        cout<<b<<' '<<c<<' '<<a;
    else if(b>=a&&a>=c)
        cout<<c<<' '<<a<<' '<<b;
    else if(b>=c&&a<=c)
        cout<<a<<' '<<c<<' '<<b;
    else if(c>=a&&a>=b)
        cout<<b<<' '<<a<<' '<<c;
    else if(c>=b&&a<=b)
        cout<<a<<' '<<b<<' '<<c;       
}