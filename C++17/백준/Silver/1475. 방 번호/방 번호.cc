#include <iostream>
using namespace std;
int arr[10];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    while(n){
        arr[n%10]++;
        n/=10;
    }
    arr[6] += arr[9]+1;
    arr[6]/=2;
    arr[9] = 0;
    int answer = 0;
    for(int i = 0; i < 9; i++)
        answer = max(answer,arr[i]);
    cout<<answer;
}