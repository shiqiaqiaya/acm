#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> adj(n + 1);

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y), adj[y].push_back(x);
    }

    vector<array<int, 20>> dp(n + 1);

    auto dfs = [&](auto & dfs, int u, int fa) -> void {
        for (auto & v : adj[u]) {
            if (v == fa) continue;
            dfs(dfs, v, u);
            for (int i = 0; i < 20; i++) {
                int tmp = 4e18;
                for (int j = 0; j < 20; j++) {
                    if (i == j) continue;
                    tmp = min(tmp, dp[u][i] + dp[v][j]);
                }
                dp[u][i] = tmp;
            }
        }
        for (int i = 0; i < 20; i++) {
            dp[u][i] += (i + 1) * a[u];
        }
    };

    dfs(dfs, 1, 0);

    cout << *min_element(dp[1].begin(), dp[1].end()) << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}