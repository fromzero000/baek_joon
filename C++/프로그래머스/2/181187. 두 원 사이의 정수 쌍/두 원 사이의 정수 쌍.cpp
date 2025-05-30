#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    for(long long i = 0; i <= r2; i++){
        //r1^2 <= i^2 + x^2 <= r2^2 ==> r1 <=i^2+x^2
        long long smallCircle;
        long long bigCircle = floor(sqrt(pow(r2,2)-pow(i,2)));
        if(i<=r1) smallCircle = ceil(sqrt(pow(r1,2)-pow(i,2)));
        else smallCircle = 0;
        answer += bigCircle - smallCircle + 1;
    }
    answer *= 4; answer -= (r2-r1+1)*4;
    return answer;
}