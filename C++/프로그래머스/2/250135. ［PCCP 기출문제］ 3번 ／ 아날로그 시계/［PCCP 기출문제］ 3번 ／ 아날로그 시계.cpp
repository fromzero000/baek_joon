#include <string>
#include <vector>

using namespace std;
int answer;
vector<double> angle(int h, int m, int s){
    double _h = h%12*30+m*0.5+s/120.0;
    double _m = m*6+s*0.1;
    double _s = s*6.0;
    return vector<double>({_h,_m,_s});
}
bool ring(const vector<double>& cur, const vector<double>& next, int h_m, int s){
    return (cur[h_m]>cur[s]&&next[h_m]<=next[s])||(cur[s]==354&&cur[h_m]>354);
     
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int start = h1*3600+m1*60+s1;
    int end = h2*3600+m2*60+s2;
    
    for(int i = start; i < end; i++){
        auto cur = angle(i/3600, i%3600/60,i%60);
        auto next = angle((i+1)/3600, (i+1)%3600/60, (i+1)%60);
        
        auto h = ring(cur,next,0,2);
        auto m = ring(cur,next,1,2);
        
        if(h&&m){
            answer += (next[1]==next[0]?1:2);
        }
        else if(h||m) answer++;
    }
    if(start==0||start==43200) answer++;
    return answer;
}