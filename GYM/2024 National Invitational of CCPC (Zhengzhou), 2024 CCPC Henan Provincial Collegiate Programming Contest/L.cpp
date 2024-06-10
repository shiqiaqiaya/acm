#include<bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m + 1), dp(m + 1, 4e18);

    dp[0] = 0;

    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        dp[i] = a[i] * (a[i] + 1) / 2 + a[i];
        for (int j = 1; j * j * j * j <= dp[i] && i - j >= 0; j++) {
            dp[i] = min(dp[i - j] + j * j * j * j + a[i], dp[i]);
        }
    }

    cout << dp.back() << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;

    while (t--) {
        QAQ();
    }
}