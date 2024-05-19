#include <bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n;
    cin >> n;

    vector<array<int, 2>> a(n + 1);

    vector<int> dp(1ll << n, -1);

    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }

    auto dfs = [&](auto & dfs, int msk) -> int {
        if (dp[msk] != -1) {
            return dp[msk];
        }

        set<int> s;

        for (int i = 0; i < n; i++) {
            if (msk >> i & 1) continue;
            for (int j = 0; j < i; j++) {
                if (msk >> j & 1) continue;
                if (a[i][0] != a[j][0] && a[i][1] != a[j][1]) continue;
                s.insert(dfs(dfs, msk | (1ll << i) | (1ll << j)));
            }
        }

        int now = 0;

        for (auto & x : s) {
            if (x == now) {
                now++;
            } else {
                break;
            }
        }

        return dp[msk] = now;
    };

    if (dfs(dfs, 0)) {
        cout << "Takahashi\n";
    } else {
        cout << "Aoki\n";
    }
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