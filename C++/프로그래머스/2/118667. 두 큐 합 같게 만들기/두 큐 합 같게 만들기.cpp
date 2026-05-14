#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int n = queue1.size();
    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0LL);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0LL);
    int idx1 = 0, idx2 = 0;
    while(answer <= 3*n)
    {
        if(sum1 == sum2) return answer;
        if(sum1 > sum2)
        {
            if(idx1 < n)
            {
                sum1 -= queue1[idx1];
                sum2 += queue1[idx1++];
            }
            else
            {
                sum1 -= queue2[idx1-n];
                sum2 += queue2[idx1++-n];
            }
        }
        else if(sum1 < sum2)
        {
            if(idx2 < n)
            {
                sum2 -= queue2[idx2];
                sum1 += queue2[idx2++];
            }
            else
            {
                sum2 -= queue1[idx2-n];
                sum1 += queue1[idx2++-n];
            }
        }
        answer++;
    }
    
    
    return -1;
}