#include <iostream>
using namespace std;

int main(){
    int n,t;
    cin>>n>>t;
    int work, answer = 0;
    for(int i = 1; i <= n&& t > 0; i++){
        cin>>work;
        t-=work;
        if(t>=0){
            answer+=1;
        }
    }
    cout<<answer;
}
