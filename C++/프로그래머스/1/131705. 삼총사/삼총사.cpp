#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    
    for(auto i = 0; i < number.size()-2; i++){
        for(auto j = i+1; j < number.size()-1; j++){
            for(auto k = j+1; k < number.size(); k++){
                if(number[i]+number[j]+number[k]) continue;
                else answer++;
            }
        }
    }
    return answer;
}