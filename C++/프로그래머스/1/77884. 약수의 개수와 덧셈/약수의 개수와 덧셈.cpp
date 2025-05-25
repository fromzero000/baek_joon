#include <string>
#include <vector>

using namespace std;
bool isSquare(int n){
    for(auto i = 0; i*i <= n; i++){
        if(i*i==n) return true;
    }
    return false;
}
int solution(int left, int right) {
    int answer = 0;
    for(;left<=right;left++){
        if(isSquare(left)) answer-=left;
        else answer+=left;
    }
    return answer;
}