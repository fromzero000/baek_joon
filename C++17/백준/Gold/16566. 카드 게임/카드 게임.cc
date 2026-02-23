#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<int> minsu;
vector<int> nextCard;

int findNode(int idx)
{
    if(nextCard[idx] == idx) return idx;
    return nextCard[idx] = findNode(nextCard[idx]);
}

void unionNode(int used, int next)
{
    used = findNode(used);
    next = findNode(next);
    
    if(used!=next)
    {
        nextCard[used] = next;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    minsu.resize(m);
    nextCard.resize(m+1);
    for(int i = 0; i < m; i++)
    {
        cin >> minsu[i];
    }
    sort(minsu.begin(), minsu.end());
    for(int i = 0; i <= m; i++)
        nextCard[i] = i;
    int chulsu;
    for(int i =0; i < k; i++)
    {
        cin >>chulsu;
        int cur = upper_bound(minsu.begin(), minsu.end(), chulsu)-minsu.begin();
        cur = findNode(cur);
        cout << minsu[cur] << '\n';
        unionNode(cur, cur+1);
    }
    
}