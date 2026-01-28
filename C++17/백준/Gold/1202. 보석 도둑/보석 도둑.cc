#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> jewels(N);
    for (int i = 0; i < N; i++) 
    {
        cin >> jewels[i].first >> jewels[i].second;
    }

    vector<int> bags(K);
    for (int i = 0; i < K; i++) 
    {
        cin >> bags[i];
    }

    sort(jewels.begin(), jewels.end());

    sort(bags.begin(), bags.end());

    priority_queue<int> pq;
    
    long long total_value = 0;
    int j_idx = 0;
    for (int i = 0; i < K; i++) 
    {
        while (j_idx < N && jewels[j_idx].first <= bags[i]) 
        {
            pq.push(jewels[j_idx].second);
            j_idx++;
        }
        if (!pq.empty()) 
        {
            total_value += pq.top();
            pq.pop();
        }
    }

    cout << total_value << '\n';

    return 0;
}