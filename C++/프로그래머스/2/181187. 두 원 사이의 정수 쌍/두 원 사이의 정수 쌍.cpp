#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    for(long long i = 0; i <= r2; i++){
        long long bc = sqrt(pow(r2,2)-pow(i,2));
        long long sc = (i<=r1)?ceil(sqrt(pow(r1,2)-pow(i,2))):0;
        answer += bc - sc + 1;
        
    }
    answer *= 4;
    answer -= 4*(r2-r1+1);
    return answer;
}