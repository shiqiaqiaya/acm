#include <bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, k;
    cin >> n >> k;

    vector dp(n + 1, vector<int>(k + 1, 4e18));

    dp[0][0] = 0;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        for (int o = 1; o <= min(i, k + 1); o++) {
            int tmp = *min_element(a.begin() + i - o + 1, a.begin() + i + 1);
            for (int j = 0; j + o - 1 <= k; j++) {
                dp[i][j + o - 1] = min(dp[i][j + o - 1], dp[i - o][j] + o * tmp);
            }
        }
    }

    int ans = 4e18;

    for (int i = 0; i <= k; i++) {
        ans = min(ans, dp[n][i]);
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