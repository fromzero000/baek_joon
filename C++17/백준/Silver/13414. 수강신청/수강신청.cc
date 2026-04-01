#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k, l;
    cin >> k >> l;
    
    vector<string> students(l);
    map<string, int> cnt;
    for(int i = 0; i < l; i++)
    {
        cin >> students[i];
        if(cnt.find(students[i])!=cnt.end())
            cnt[students[i]]++;
        else cnt[students[i]] = 1;
    }
    for(int i = 0; i < l; i++)
    {
        if(k < 1) break;
        if(cnt[students[i]] == 1)
        {
            cout << students[i] << '\n';
            k--;
        }
        else cnt[students[i]]--;
    }
}