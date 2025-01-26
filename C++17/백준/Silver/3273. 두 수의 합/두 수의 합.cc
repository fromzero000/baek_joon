#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n,x,count = 0;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    cin>>x;
    sort(a,a+n);
    for(int s = 0, e = n - 1; s < e;){
        if(a[s]+a[e]==x){
            count++;
            s++;
            e--;
        }
            
        else if(a[s]+a[e]>x)
            e--;
        else
            s++;
    }
    cout<<count;
}
