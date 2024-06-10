#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n;
    cin >> n;

    vector adj(n + 1, vector<int>());

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }

    vector<array<array<int, 2>, 2>> dp(n + 1);

    auto dfs = [&](auto & dfs, int u, int fa) -> void {
        dp[u][0][1] = 1, dp[u][1][1] = 1;
        int sum = 1, sum2 = 0;
        for (auto & v : adj[u]) {
            if (v == fa) continue;
            dfs(dfs, v, u);
            dp[u][0][0] += max(dp[v][0][1], dp[v][0][0]);
            dp[u][0][1] += dp[v][0][0];
            sum += dp[v][0][0], sum2 += max(dp[v][0][0], dp[v][0][1]);
        }
        for (auto & v : adj[u]) {
            dp[u][1][0] = max(dp[u][1][0], sum2 - max(dp[v][0][0], dp[v][0][1]) + max(dp[v][1][0], dp[v][1][1]));
            dp[u][1][1] = max(dp[u][1][1], sum - dp[v][0][0] + dp[v][1][0]);
        }
        dp[u][1][0] = max(dp[u][1][0], dp[u][0][0] + (adj[u].size() == 1));
    };

    dfs(dfs, 1, 0);

    cout << max(dp[1][1][0], dp[1][1][1]) << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}