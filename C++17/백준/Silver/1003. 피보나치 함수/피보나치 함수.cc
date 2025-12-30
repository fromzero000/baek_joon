#include <bits/stdc++.h>
using namespace std;

int fibonaccies0[41];
int fibonaccies1[41];

void fibonaccies(){
    for(int i = 0; i <= 40; i++){
        if(i == 0) {
            fibonaccies0[i] = 1;
            fibonaccies1[i] = 0;
        }
        else if(i == 1){
            fibonaccies1[i] = 1;
            fibonaccies0[i] = 0;
        }
        else{
            fibonaccies0[i] = fibonaccies0[i-1]+fibonaccies0[i-2];
            fibonaccies1[i] = fibonaccies1[i-1]+fibonaccies1[i-2];
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, N;
    cin >> T;
    fibonaccies();
    while(T--){
        cin >> N;
        cout<<fibonaccies0[N]<<' '<<fibonaccies1[N]<<'\n';
    }
}