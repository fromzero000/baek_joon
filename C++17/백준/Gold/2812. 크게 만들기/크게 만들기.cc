#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    string result{};
    string input;
    cin >> input;
    for(char i : input)
    {
        while(k > 0 && !result.empty() && result.back() < i)
        {
            result.pop_back();
            k--;
        }
        result.push_back(i);
    }
    for(int i = 0; i < result.length()-k; i++)
        cout << result[i];
    
}