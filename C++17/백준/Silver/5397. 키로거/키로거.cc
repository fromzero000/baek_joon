#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--) {
        string key_log;
        cin >> key_log;

        list<char> password;
        auto cur = password.begin();

        for (const auto& c : key_log) {
            if (c == '<') {
                if (cur != password.begin()) cur--;
            }
            else if (c == '>') {
                if (cur != password.end()) cur++;
            }
            else if (c == '-') {
                if (cur != password.begin()) {
                    cur--; 
                    cur = password.erase(cur); 
                }
            }
            else password.insert(cur, c);
        }

        for (const auto& c : password) cout << c;
        cout << '\n';
    }
}