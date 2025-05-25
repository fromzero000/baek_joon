#include <string>
#include <vector>

using namespace std;
bool possible(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t, long long mid){
    auto cities = g.size();
    long long gold = 0;
    long long silver = 0;
    long long both = 0;
    for(size_t i = 0; i < cities; i++){
        long long time = t[i];
        long long round_trip = time*2;
        
        long long trips = mid/round_trip;
        if(mid%round_trip>=time) trips++;
        long long _max = trips*w[i];
        gold+=min((long long)g[i], _max);
        silver+=min((long long)s[i], _max);
        both+=min((long long)g[i]+s[i], _max);
    }
    return gold>=a&&silver>=b&&both>=a+b;
}
long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    
    long long start = 0;
    long long end = 10e14;
    long long answer = end;
    while(start <= end){
        long long mid = (start+end)/2;
        if(possible(a,b,g,s,w,t, mid)){
            answer = mid;
            end = mid-1;
        }
        else start = mid+1;
    }
    
    
    return answer;
}