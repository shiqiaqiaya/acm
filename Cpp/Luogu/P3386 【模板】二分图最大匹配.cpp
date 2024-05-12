#include<bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n, m, e;
    cin >> n >> m >> e;
    vector<vector<int>> adj(n + m + 1);

    for (int i = 1; i <= e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v + n), adj[v + n].push_back(u);
    }

    vector<int> mch;

    int ans = [&](int n, int m, int ans = 0) {
        mch = vector<int>(n + m + 1);
        vector<int> vis(n + m + 1);

        for (int i = 1; i <= n; i++) {
            fill(vis.begin() + n + 1, vis.end(), 0);

            auto dfs = [&](auto & dfs, int u) -> bool {
                for (auto & v : adj[u]) {
                    if (vis[v]) continue;
                    vis[v] = 1;
                    if (!mch[v] || dfs(dfs, mch[v])) {
                        mch[u] = v, mch[v] = u;
                        return true;
                    }
                }
                return false;
            };

            ans += dfs(dfs, i);
        }

        return ans;
    } ();

    cout << ans << "\n";
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