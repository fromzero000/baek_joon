#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    int n = weights.size();
    vector<int> torques(4001, 0);
    vector<long long> weightCnt(1001, 0);
    
    for(int i = 0; i < n; i++)
        weightCnt[weights[i]]++;
    for(int i = 0; i < n; i++)
        for(int pos : {2, 3, 4})
            torques[weights[i]*pos]++;
    
    for(int i = 200; i <= 4000; i++)
        if(torques[i] > 1) answer += (long long)torques[i]*(torques[i]-1)/2;
    
    for(int i = 100; i <= 1000; i++) 
    {
        if(weightCnt[i] > 1) 
        {
            long long sameWeightPairs = weightCnt[i]*(weightCnt[i] - 1)/2;
            answer -= sameWeightPairs*2; 
        }
    }
    return answer;
}