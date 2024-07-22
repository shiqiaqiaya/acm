#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int m;
    cin >> m;
    int n = 2 * m;
    n++;

    vector<int> a(n + 1), res(m + 1);
    vector<vector<int>> p(m + 1);

    p[0].push_back(0), p[0].push_back(n + 1);

    for (int i = 1; i < n; i++) {
        cin >> a[i];
        p[a[i]].push_back(i);
    }

    for (int i = m; ~i; i--) {
        vector<int> dp(n + 1);
        int l = p[i][0], r = p[i][1];
        for (int j = l; j <= r; j++) {
            dp[j] = dp[j - 1] + i;
            int tl = p[a[j]][0];
            if (tl == j) continue;
            if (l <= tl) {
                dp[j] = max(dp[j], dp[tl - 1] + res[a[j]]);
            }
        }
        res[i] = dp[r];
    }
    cout << res[0] << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        QAQ();
    }
}