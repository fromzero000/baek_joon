#include <bits/stdc++.h>
using namespace std;


string n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    int multipleOf3 =0;
    bool multipleOf10 = 0;
    for(int i = 0; i < n.length(); i++)
    {
        if(n[i] == '0') multipleOf10 = 1;
        multipleOf3 += (n[i] - '0');
    }
    sort(n.begin(), n.end(), greater<char>());
    if(multipleOf10 && multipleOf3%3 == 0)
        cout << n;
    else cout << -1;
}