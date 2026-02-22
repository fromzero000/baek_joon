#include <bits/stdc++.h>
using namespace std;

int n;
long long b;
vector<vector<int>> mat;
vector<vector<int>> result;

vector<vector<int>> multiply(long long cnt, vector<vector<int>>& a, vector<vector<int>>& b)
{
    if(cnt == 0)
        return b;
    if(cnt == 1)
    {
        vector<vector<int>> temp(n, vector<int>(n));
        for(int i = 0; i < n; i++)
        {
            vector<int> tar = a[i];
            
            for(int j = 0; j < n; j++)
            {
                int t = 0;
                for(int k = 0; k < n; k++)
                {
                    t += tar[k]*b[k][j];
                }
                temp[i][j] = t%1000;
            }
        }
        return temp;    
    }
    if(cnt%2 == 0)
    {
        vector<vector<int>> temp = multiply(1, a, b);
        return multiply(cnt/2, temp, temp);
    }
    else
    {
        vector<vector<int>> temp1 = multiply(1, a, b);
        vector<vector<int>> temp2 = multiply(cnt-1, a, b);
        return multiply(1, temp1, temp2);
    }
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> b;
    
    mat.resize(n);
    result.resize(n);
    
    for(int i = 0; i < n; i++)
    {
        vector<int> temp(n);
        for(int j = 0; j < n; j++)
        {
            cin >> temp[j];
        }
        mat[i] = temp;
    }
    
    for(int i = 0; i < n; i++)
    {
        result[i] = vector<int>(n);
        result[i][i] = 1;
    }
    
    result = multiply(b, mat, result);
    
    for(const vector<int>& v : result)
    {
        for(const int& i : v)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }
}