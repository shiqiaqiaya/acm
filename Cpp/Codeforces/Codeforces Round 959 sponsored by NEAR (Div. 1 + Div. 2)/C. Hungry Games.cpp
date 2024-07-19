#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1), pre(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    int sum = 0, ans = 0;

    vector<int> dp(n + 2);

    for (int i = n; i; i--) {
        int xx = x + pre[i - 1];
        auto it = upper_bound(pre.begin() + 1, pre.end(), xx);
        if (it != pre.end()) {
            dp[i] += dp[it - pre.begin() + 1];
        }
        dp[i] += (it - pre.begin() - i);
        ans += dp[i];
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