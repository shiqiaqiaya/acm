#include <bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> dp(1ll << 2 * k, 4e18);

    dp[0] = 0;

    vector<array<int, 3>> a(k);

    vector mp(n + 4, vector<int>(m + 4, -1));

    for (int i = 0; i < k; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        mp[a[i][0]][a[i][1]] = i;
    }

    vector<array<int, 2>> D = {{0, 0}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    auto get = [&](int x, int y, int msk) {
        for (auto & [dx, dy] : D) {
            int tx = dx + x, ty = dy + y;
            if (tx < 0 || ty < 0) continue;
            if (mp[tx][ty] != -1) {
                int tmp = msk >> (2 * mp[tx][ty]) & 3;
                if (tmp) {
                    tmp--;
                }
                msk &= (~(3 << (2 * mp[tx][ty])));
                msk |= (tmp << (2 * mp[tx][ty]));
            }
        }
        return msk;
    };

    auto dfs = [&](auto & dfs, int msk) -> int {
        if (dp[msk] != 4e18) {
            return dp[msk];
        }
        for (int i = 0; i < k; i++) {
            if (msk >> (2 * i) & 3) {
                for (auto & [dx, dy] : D) {
                    int tx = a[i][0] + dx, ty = a[i][1] + dy;
                    if (tx < 0 || ty < 0) continue;
                    int nmsk = get(tx, ty, msk);
                    dp[msk] = min(dfs(dfs, nmsk) + 1, dp[msk]);
                }
            }
        }
        return dp[msk];
    };

    int msk = 0;

    for (int i = 0; i < k; i++) {
        msk |= (a[i][2] << 2 * i);
    }

    cout << dfs(dfs, msk) << "\n";
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