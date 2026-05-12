#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;

vector<long long> solution(vector<int> arr, long long l, long long r) {
    vector<long long> answer(2, 0);
    l--;r--;
    vector<long long> brr(arr.size(), 0);
    vector<long long> sum(arr.size(), 0);
    long long n = accumulate(arr.begin(), arr.end(), 0ll);
    brr[0] = 0;
    sum[0] = 1LL*arr[0]*arr[0];
    for(int i = 1; i < arr.size(); i++)
    {
        brr[i] = brr[i-1]+arr[i-1];
        sum[i] = sum[i-1]+1LL*arr[i]*arr[i];
    }
    
    auto getVal = [&](long long idx)->int{
        int pos = upper_bound(brr.begin(), brr.end(), idx)-brr.begin()-1;
        return arr[pos];
    };
    

    
    auto getSum = [&](long long s, long long e)->long long{
        int sB = upper_bound(brr.begin(), brr.end(), s) - brr.begin()-1;
        int eB = upper_bound(brr.begin(), brr.end(), e) - brr.begin()-1;
        if(sB == eB) return (e-s+1)*arr[sB];
        
        long long result = 0;
        if(eB-1 >= sB+1) result += sum[eB-1]-sum[sB];
        result += (brr[sB]+arr[sB]-s)*(long long)arr[sB];
        result += (e-brr[eB]+1LL)*arr[eB];
        return result;
    };
    answer[0] = getSum(l, r);
    
    vector<long long> points;
    points.push_back(0);
    points.push_back(n-(r-l));
    
    for(int i = 0; i < brr.size(); i++)
    {
        long long pos = brr[i];
        if(pos > 0 && pos <= n-(r-l+1)) points.push_back(pos);
        long long pos1 = brr[i]-(r-l);
        if(pos1 > 0 && pos1 <= n-(r-l+1)) points.push_back(pos1);
    }
    
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());
    
    for(int i = 0; i < points.size()-1; i++)
    {
        long long L = points[i], R = points[i+1]-1;
        long long cur = getSum(L, L+(r-l));
        long long d = getVal(L+(r-l+1))-getVal(L);
        long long diff = answer[0] - cur;
        if(d == 0)
        {
            if(diff == 0) answer[1] += R-L+1;
            else continue;
        }
        else
        {
            if(diff%d == 0 && diff/d >= 0 && diff/d <= R-L) answer[1]++;
            else continue;
        }
    }
    
    return answer;
}
