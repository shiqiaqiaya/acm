#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 1), sum(n + 1);
    vector dp(n + 1, vector<int>(n + 1, 4e18)), opt(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0, opt[i][i] = i;
    }

    for (int len = 2; len <= n; len++) {
        for (int j = 1, i = len; i <= n; j++, i++) {
            for (int k = opt[j][i - 1]; k <= min(i - 1, opt[j + 1][i]); ++k) {
                if (dp[j][i] > dp[j][k] + dp[k + 1][i] + sum[i] - sum[j - 1]) {
                    dp[j][i] = dp[j][k] + dp[k + 1][i] + sum[i] - sum[j - 1];
                    opt[j][i] = k;
                }
            }
        }
    }

    cout << dp[1][n] << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;

    while (t--) {
        QAQ();
    }
}