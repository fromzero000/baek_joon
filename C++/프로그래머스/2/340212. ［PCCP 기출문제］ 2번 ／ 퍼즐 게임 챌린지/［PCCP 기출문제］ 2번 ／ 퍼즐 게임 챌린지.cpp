#include <string>
#include <vector>

using namespace std;
long long getTime(vector<int> diffs, vector<int> times, int level){
    long long answer = 0;
    answer += (diffs[0] - level<=0)?times[0]:times[0]*(diffs[0]-level)+times[0];
    for(int i = 1; i < diffs.size(); i++){
        answer += (diffs[i]-level<=0)?times[i]:(diffs[i] - level)*(times[i]+times[i-1])+times[i];
    }
    return answer;
}
int solution(vector<int> diffs, vector<int> times, long long limit) {
    
    int e = 100000;
    int s = 1;
    int mid;
    int answer = e;
    while(s<=e){
        int mid = (e+s)/2;
        if(getTime(diffs, times, mid)<=limit){
            answer = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    
    return answer;
}