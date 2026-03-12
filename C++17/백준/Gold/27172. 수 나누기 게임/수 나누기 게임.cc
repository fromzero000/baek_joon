#include <bits/stdc++.h>
using namespace std;

int n;

bool selected[1000001];
int its[1000001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    vector<int> scores(n);
    vector<int> players(n);
    for(int i = 0; i < n; i++)
    {
        cin >> players[i];
        its[players[i]] = i;
        selected[players[i]] = 1;
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = players[i]*2; j <= 1000000; j+=players[i])
        {
            if(selected[j])
            {
                scores[its[j]]--;
                scores[i]++;
            }
        }
    }
    
    for(const int& score : scores)
        cout << score << ' ';
}