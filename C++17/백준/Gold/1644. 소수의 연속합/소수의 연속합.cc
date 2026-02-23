#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> primes;

void findPrimes()
{
    primes.push_back(2);
    for(int i = 3; i <= n; i++)
    {
        bool isPrime = 1;
        for(int j = 2; j*j <= i; j++)
        {
            if(i%j == 0)
            {
                isPrime = 0;
                break;
            }
        }
        if(isPrime)
            primes.push_back(i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    findPrimes();
    int st = 0, en = 0;
    int cnt = 0;
    while(st <= en && en < primes.size())
    {
        int sum = 0;
        for(int i = st; i <= en; i++)
        {
            sum += primes[i];
        }
        if(sum < n)
        {
            en++;
        }
        else if(sum > n)
        {
            st++;
        }
        else
        {
            cnt++;
            en++;st++;
        }
    }
    cout << cnt;
}