#include <bits/stdc++.h>
using namespace std;
//30 * (100000 + 100000*100000)

bool isPalindrome(const string& s, int l, int r)
{
    while(l<r)
    {
        if(s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int l = 0, r = s.length()-1;
        while(l < r)
        {
            if(s[l] != s[r])
            {
                if(isPalindrome(s, l+1, r)||isPalindrome(s, l, r-1)) cout << "1\n";
                else cout << "2\n";
                break;
            }
            r--;
            l++;
        }
        if(l>=r)
            cout << "0\n";
    }
}