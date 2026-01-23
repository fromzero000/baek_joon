#include <bits/stdc++.h>
using namespace std;


int n, s;
int nums[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> s;
    int input;
    for(int i = 1; i <= n; i++)
    {
        cin >> input;
        nums[i] = nums[i-1] + input;
    }
    
    int st = 0, en = 1;
    int len = 0x7fffffff;

    while(st <= en && en <= n)
    {
        int current = nums[en] - nums[st];
        if(current >= s)
        {
            len = min(en - st, len);
            st++;
        }
        else
        {
            en++;
        }
    }
    cout << (len==0x7fffffff?0:len);
}