#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    s = " " + s;
    t = " " + t;

    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            cout << "YES\n";
            return;
        }
        if (t[i] != s[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}