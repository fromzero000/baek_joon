#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int n){
    if(n<2) return false;

    for(int i = 2; i*i <= n; i++){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    int N,n,n_primes = 0;
    cin>>N;
    for(int i; i < N; i++){
        cin>>n;
        if(isPrime(n)) n_primes++;
    }
    cout<<n_primes;
}