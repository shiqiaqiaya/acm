#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, m;
    cin >> n >> m;

    vector adj(n + 1, vector<int>());
    vector<int> du(n + 1);
    vector<array<int, 3>> e(m + 1);

    for (int i = 1; i <= m; i++) {
        cin >> e[i][0] >> e[i][1] >> e[i][2];
        du[e[i][0]] ^= e[i][2];
        du[e[i][1]] ^= e[i][2];
        adj[e[i][0]].push_back(i);
        adj[e[i][1]].push_back(i);
    }

    vector<int> vis(n + 1);

    auto dfs = [&](auto && dfs, int u) -> void {
        vis[u] = 1;
        for (auto & i : adj[u]) {
            int v = u ^ e[i][0] ^ e[i][1];
            if (e[i][2] || vis[v]) {
                continue;
            }
            dfs(dfs, v);
            if (du[v]) {
                du[v] ^= 1, du[u] ^= 1, e[i][2] = 1;
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        dfs(dfs, i);
        if (du[i]) {
            cout << "NO\n";
            return;
        }
    }

    vector<int> path;
    auto eluer_path = [&](auto && eluer_path, int u) -> void {
        while (adj[u].size()) {
            int i = adj[u].back();
            adj[u].pop_back();
            if (!e[i][2]) continue;
            e[i][2] = 0;
            int v = u ^ e[i][0] ^ e[i][1];
            eluer_path(eluer_path, v);
        }
        path.push_back(u);
    };

    eluer_path(eluer_path, 1);

    cout << "YES\n" << path.size() - 1 << "\n";
    
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " \n"[i + 1 == path.size()];
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}