#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n;
    cin >> n;

    vector<string> a(2);

    for (int i = 0; i < 2; i++) {
        cin >> a[i];
        a[i] = " " + a[i];
    }

    vector dp(2, vector<int>(n + 1));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[0][i] == 'R' && a[1][i] == 'R') {
            dp[0][i] = max({1ll, dp[0][i - 1] + 1, dp[1][i - 1] + 2});
            dp[1][i] = max({1ll, dp[0][i - 1] + 2, dp[1][i - 1] + 1});
        } else if (a[0][i] == 'R' && a[1][i] == 'W') {
            dp[0][i] = max({1ll, dp[0][i - 1] + 1});
        } else if (a[0][i] == 'W' && a[1][i] == 'R') {
            dp[1][i] = max(1ll, dp[1][i - 1] + 1);
        } else {

        }

        ans = max({ans, dp[0][i], dp[1][i]});
    }

    cout << max(0ll, ans - 1) << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        QAQ();
    }
}