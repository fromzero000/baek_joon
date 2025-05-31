#include <string>
#include <vector>
#include <numeric>


using namespace std;

int power[3][3] = {{1,1,1},{5,1,1},{25,5,1}};
int answer = 50*25;
//count = minerals.size()에 도달하면 종료

int toVal(const string& mineral){
    if(mineral=="diamond") return 0;
    else if(mineral=="iron") return 1;
    else return 2;
}
void DFS(vector<int>& picks, int sum, vector<string>& minerals, int count){
    if(count == minerals.size()){
        answer = min(answer, sum);
        return;
    }
    for(int i = 0; i < 3; i++){
        if(picks[i]>0){
            picks[i]--;
            int temp = sum;
            int tempcnt = count;
            for(int j = tempcnt; j < count+5&&tempcnt<minerals.size(); j++){
                temp += power[i][toVal(minerals[j])];
                tempcnt++;
            }
            DFS(picks,temp,minerals, tempcnt);
            picks[i]++;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int sum_ = picks[0]+picks[1]+picks[2];
    if(sum_*5<minerals.size()){
        vector<string> temp;
        for(auto i = 0; i < sum_*5; i++){
            temp.push_back(minerals[i]);
        }
        minerals = temp;
    }
    int sum = 0;
    int count = 0;
    DFS(picks, sum, minerals, count);
    return answer;
}