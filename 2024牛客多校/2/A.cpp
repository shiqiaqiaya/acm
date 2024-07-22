#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, m, k, x, y;
    char t, op;
    cin >> n >> m >> k >> x >> y >> t;

    if (x + y & 1) {
        if (t == 'B') {
            op = 'A';
        } else {
            op = 'B';
        }
    } else {
        if (t == 'A') {
            op = 'A';
        } else {
            op = 'B';
        }
    }

    int mn = n + m, mx = n + m;

    vector<string> ans(n + 1, " ");
    ans[0][0] = op;

    for (int i = 1; i <= n; i++) {
        ans[i][0] = ans[i - 1][0] == 'A' ? 'B' : 'A';
        for (int j = 1; j <= m; j++) {
            ans[i] += ans[i].back() == 'A' ? 'B' : 'A';
            if (ans[i].back() == 'A' && i + 1 <= n && j + 1 <= m) {
                mx++;
            }
        }
    }

    if (k < n + m || k > mx) {
        cout << "No\n";
        return;
    }

    int sum = mx;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (sum > k && ans[i][j] == 'A') {
                if (ans[i + 1][j] == 'B' && ans[i][j + 1] == 'B' && ans[i + 1][j + 1] == 'A') {
                    sum--;
                    if (i == x && j == y) {
                        ans[i][j + 1] = 'A';
                    } else {
                        ans[i][j] = 'B';
                    }
                }
            }
        }
    }

    if (sum != k) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        cout << string(ans[i].begin() + 1, ans[i].end()) << "\n";
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