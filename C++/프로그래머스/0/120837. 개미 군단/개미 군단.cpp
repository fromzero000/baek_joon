#include <string>
#include <vector>
#define ultra 5
#define zergling 3
#define drone 1
using namespace std;

int solution(int hp) {
    int answer = 0;
    answer += (hp/ultra);
    hp %= ultra;
    answer += (hp/zergling);
    hp %= zergling;
    answer += (hp/drone);
    
    return answer;
}