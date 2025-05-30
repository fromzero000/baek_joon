#include <string>
#include <vector>
#include <map>
using namespace std;
vector<map<vector<int>, int>> time_mp(100001);
int answer;
void run_(const vector<int>& route, const vector<vector<int>>& points){
    int t = 0;
    vector<int> final;
    for(int i = 0; i < route.size()-1; i++){
        auto start = points[route[i]-1];
        auto end = points[route[i+1]-1];
        final = end;
        while(start!=end){
            time_mp[t][start]++;
            if(time_mp[t][start]==2) answer++; 
            if(start[0]!=end[0]){
                start[0] += (start[0]<end[0])?1:-1;
            }
            else if(start[1]!=end[1]){
                start[1] += (start[1]<end[1])?1:-1;
            }
            t++;
        }
    }
    time_mp[t][final]++;
    if(time_mp[t][final]==2) answer++;
}
int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    for(const auto& route : routes){
        run_(route,points);
    }
    return answer;
}