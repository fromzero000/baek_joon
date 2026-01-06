#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> dp(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        dp[i] = 1;

        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
        }

        if (maxLength < dp[i]) maxLength = dp[i];
    }

    cout << maxLength << endl;

    return 0;
}