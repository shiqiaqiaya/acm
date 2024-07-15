#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;

    s = "L" + s + "L";

    int tmp = 0;

    for (int i = 0; i <= n; ) {
        if (s[i] == 'L') {
            int ok = 0;
            for (int j = m; j; j--) {
                if (i + j <= n + 1 && s[i + j] == 'L') {
                    i += j;
                    ok = 1;
                    break;
                }
            }
            if (!ok) {
                for (int j = m; j; j--) {
                    if (i + j <= n + 1 && s[i + j] == 'W') {
                        i += j;
                        ok = 1;
                        break;
                    }
                }
            }
            if (!ok) {
                cout << "NO\n";
                return;
            }
        } else if (s[i] == 'W') {
            tmp++;
            i++;
        } else if (s[i] == 'C') {
            cout << "NO\n";
            return;
        }
    }

    if (tmp <= k) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}