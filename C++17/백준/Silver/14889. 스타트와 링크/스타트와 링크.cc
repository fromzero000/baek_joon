#include <bits/stdc++.h>
using namespace std;

int N;
int S[22][22];
bool visited[22];
int min_diff = 1e9;

void dfs(int idx, int count) 
{
    if (count == N / 2) 
    {
        int start_score = 0;
        int link_score = 0;

        for (int i = 1; i <= N; i++) 
        {
            for (int j = 1; j <= N; j++) 
            {
                if (visited[i] == true && visited[j] == true) 
                {
                    start_score += S[i][j];
                }
                else if (visited[i] == false && visited[j] == false) 
                {
                    link_score += S[i][j];
                }
            }
        }

        int diff = abs(start_score - link_score);
        min_diff = min(min_diff, diff);

        if (min_diff == 0) 
        {
            cout << 0 << "\n";
            exit(0);
        }
        
        return;
    }

    for (int i = idx; i <= N; i++) 
    {
        if (!visited[i]) 
        {
            visited[i] = true;
            dfs(i + 1, count + 1);
            visited[i] = false;
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= N; j++) 
        {
            cin >> S[i][j];
        }
    }

    dfs(1, 0);

    cout << min_diff << "\n";

    return 0;
}