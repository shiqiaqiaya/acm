#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, m, q;
    cin >> n >> m >> q;

    int B = 300;

    vector adj(n + 1, vector<array<int, 2>>());
    vector<unordered_map<int, int>> mp(n + 1);

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}), adj[v].push_back({u, w});
        if (!mp[u].count(v)) {
            mp[u][v] = mp[v][u] = w;
        } else {
            mp[u][v] = mp[v][u] = min(mp[u][v], w);
        }
    }

    for (int i = 1; i <= q; i++) {
        int k;
        cin >> k;

        if (k >= B) {
            vector<int> in(n + 1), vis(n + 1), dis(n + 1, 4e18);
            int rt = 0;
            for (int i = 1; i <= k; i++) {
                cin >> rt;
                in[rt] = 1;
            }
            int res = 0;
            priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> q;
            q.push({0, rt});
            dis[rt] = 0;

            while (q.size()) {
                auto [w, u] = q.top();
                q.pop();
                if (vis[u]) continue;
                vis[u] = 1;
                res += w;

                for (auto & [v, w] : adj[u]) {
                    if (!in[v]) continue;
                    if (w < dis[v]) {
                        dis[v] = w;
                        q.push({w, v});
                    }
                }
            }

            if (in != vis) {
                cout << "-1\n";
            } else {
                cout << res << "\n";
            }
        } else {
            vector<int> id(k + 1);
            unordered_map<int, int> dis, vis;
            for (int i = 1; i <= k; i++) {
                cin >> id[i];
            }
            int res = 0;
            priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> q;
            q.push({0, id.back()});
            dis[id.back()] = 0;

            while (q.size()) {
                auto [w, u] = q.top();
                q.pop();
                if (vis.count(u)) continue;
                vis[u] = 1;
                res += w;

                for (int j = 1; j <= k; j++) {
                    int v = id[j];
                    if (u == v || !mp[u].count(v)) continue;
                    int w = mp[u][v];
                    if (!dis.count(v) || w < dis[v]) {
                        dis[v] = w;
                        q.push({w, v});
                    }
                }
            }

            if (vis.size() != k) {
                cout << "-1\n";
            } else {
                cout << res << "\n";
            }
        }
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        QAQ();
    }
}