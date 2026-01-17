#include <bits/stdc++.h>
using namespace std;

int getPriority(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    if (op == '(') return 0;
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string exp;
    cin >> exp;

    stack<char> s;
    string result = "";

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        if (c >= 'A' && c <= 'Z') {
            result += c;
        }

        else if (c == '(') {
            s.push(c);
        }

        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                result += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop();
        }

        else {
            while (!s.empty() && getPriority(s.top()) >= getPriority(c)) {
                result += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        result += s.top();
        s.pop();
    }

    cout << result << "\n";

    return 0;
}