#include<bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    string s;
    cin >> s;

    s = " " + s;

    int ok = 0, ans = 0;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '1') {
            ok = 1;
        } else {
            if (ok) {
                ans++;
                ok = 0;
            }
        }
    }

    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;

    QWQ();

    while (t--) {
        QAQ();
    }
}