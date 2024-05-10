#include <bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    string s;
    cin >> s;

    s = " " + s;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == ')') {
            s[i] = '(';
        } else if (s[i] == ']') {
            s[i] = '[';
        }
    }

    stack<int> st;

    vector<int> t1(s.size() + 1), t2(s.size() + 1);

    for (int i = 1; i < s.size(); i++) {
        if (!st.size() || s[st.top()] != s[i]) {
            int j;
            if (!st.size()) {
                j = 0;
            } else {
                j = st.top();
            }
            if (s[i] == '(') {
                t1[j]++;
            } else {
                t2[j]++;
            }
            if (t1[j] >= 2 || t2[j] >= 2) {
                cout << "No\n";
                return;
            }
            st.push(i);
        } else {
            st.pop();
        }
    }

    cout << "Yes\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    QWQ();

    while (t--) {
        QAQ();
    }
}