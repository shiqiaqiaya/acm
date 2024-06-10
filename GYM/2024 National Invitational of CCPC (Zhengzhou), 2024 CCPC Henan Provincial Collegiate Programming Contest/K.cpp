#include<bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n;
    cin >> n;
    vector<int> a(n + 1);

    vector adj(n + 1, vector<int>());

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }

    int ans = 0, now = 0, res = 0;

    auto dfs = [&](auto & dfs, int u, int fa) -> void {
        for (auto & v : adj[u]) {
            if (v == fa) continue;
            res += (a[v] * 2 >= a[u]);
            dfs(dfs, v, u);
        }
    };

    dfs(dfs, 1, 0);

    auto dfs1 = [&](auto & dfs1, int u, int fa) -> void {
        ans += now + res == n - 1;
        for (auto & v : adj[u]) {
            if (v == fa) continue;
            res -= a[v] * 2 >= a[u], now += a[u] * 2 >= a[v];
            dfs1(dfs1, v, u);
            res += a[v] * 2 >= a[u], now -= a[u] * 2 >= a[v];
        }
    };

    dfs1(dfs1, 1, 0);

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