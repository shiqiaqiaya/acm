#include <bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    string s;
    cin >> s;

    s = " " + s;

    int cnt = 0, ans = 0;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '0') {
            if (cnt) {
                ans += cnt + 1;
            }
        } else {
            cnt++;
        }
    }

    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}