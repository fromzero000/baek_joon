#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int idx = 0;
    for(const auto& member : timelogs)
    {
        int agree = schedules[idx++];
        bool onTime = true;
        int day = startday;
        for(int timelog : member)
        {
            if(day == 6 || day == 7)
            {
                day = day%7+1;
                continue;
            }
            int agreeMinute = agree/100*60+agree%100;
            int attenMinute = timelog/100*60+timelog%100;
            if(agreeMinute+10 < attenMinute) onTime = false;
            day = day%7+1;
            if(!onTime) break;
        }
        if(onTime) answer++;
    }
    return answer;
}