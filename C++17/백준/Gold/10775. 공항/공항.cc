#include <bits/stdc++.h>
using namespace std;

int g, p;
int gates[100001];
int result = 0;

int findNode(int x)
{
    if(gates[x] == x)
        return gates[x];
    else
        return gates[x] = findNode(gates[x]);
}

void unionNode(int x, int y)
{
    if(findNode(x) != findNode(y))
    {
        gates[x] = y;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> g >> p;

    for(int i = 1; i <= g; i++)
    {
        gates[i] = i;
    }
    
    for(int i = 0; i < p; i++)
    {
        int gate;
        cin >> gate;
        
        int possibleMaxGate = findNode(gate);
        if(possibleMaxGate == 0) break;
        
        result++;
        unionNode(possibleMaxGate, possibleMaxGate-1);
    }
    cout <<result;
}