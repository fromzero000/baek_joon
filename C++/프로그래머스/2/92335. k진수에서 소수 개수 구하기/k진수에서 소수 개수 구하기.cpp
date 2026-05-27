#include <string>
#include <vector>
using namespace std;

int solution(int n, int k) {
    int answer = 0;
    string nk = "";
    while(n)
    {
        nk = to_string(n%k)+nk;
        n /= k;
    }
    long long len = nk.length();
    
    auto isPrime = [](long long num)->bool{
        if(num <= 1) return false;
        if(num == 2) return true;
        
        for(long long i = 2; i*i <= num; i++)
            if(num%i == 0) return false;
        return true;
    };
    
    long long idx = 0;
    bool after0 = false;
    string token = "";
    while(idx < len)
    {
        if(nk[idx] == '0')
        {
            if(token != "" && isPrime(stoll(token)))
                answer++;
            token.clear();
        }
        else token += nk[idx];
        idx++;
    }
    if(token != "" && isPrime(stoll(token)))
        answer++;
    return answer;
}