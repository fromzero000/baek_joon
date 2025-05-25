#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 1;
    sort(targets.begin(), targets.end(), [](const auto& a, const auto& b){return a[1]==b[1]?a[0] < b[0]:a[1] < b[1];});
    int bound = targets[0][1];
    for(const auto& target : targets){
        if(target[0]>=bound){
            answer++;
            bound = target[1];
        }
    }
    return answer;
}