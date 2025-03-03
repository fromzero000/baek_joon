#include <bits/stdc++.h>
using namespace std;
#define start first
#define end second

int n,answer;
pair<int,int> schedules[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++) cin>>schedules[i].start>>schedules[i].end;
    sort(schedules,schedules+n,
         [](pair<int,int> a, pair<int,int> b){if(a.end==b.end){return a.start<b.start;}else return a.end<b.end;});
    pair<int,int> latest = {0,0};
    for(int i = 0; i < n; i++){
        if(latest.end<=schedules[i].start){
            answer++;
            latest = schedules[i];
        }
    }
    cout<<answer;
}