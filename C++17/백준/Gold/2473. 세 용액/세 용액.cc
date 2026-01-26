#include <bits/stdc++.h>
using namespace std;


vector<long long> nums(5000);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.begin()+n);
    long long min_diff = 3000000001;
    vector<long long> result(3);
    for(int i = 0; i < n-2; i++)
    {
        int left = i+1;
        int right = n-1;
        
        while(left < right)
        {
            long long current = nums[i]+nums[left]+nums[right];
            if(abs(current) < min_diff)
            {
                min_diff = abs(current);
                result[0] = nums[i];
                result[1] = nums[left];
                result[2] = nums[right];
            }
            if(current < 0)
            {
                left++;
            }
            else if(current > 0){
                right--;
            }
            else{
                cout << nums[i] << ' ' << nums[left] << ' ' << nums[right];
                return 0;
            }
        }
    }
    cout << result[0] << ' ' << result[1] << ' ' << result[2];
}