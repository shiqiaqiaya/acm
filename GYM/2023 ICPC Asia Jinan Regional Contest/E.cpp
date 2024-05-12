#include<bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + n + 1);

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v + n), adj[v + n].push_back(u);
    }

    vector<int> mch;

    int ans = [&](int n, int m, int ans = 0) {
        mch = vector<int>(n + m + 1);
        vector<int> vis(n + m + 1);

        while (1) {
            queue<int> q;
            int mx_dis = 1e9;

            vector<int> dis = vector<int>(n + m + 1, 1e9);

            for (int i = 1; i <= n; i++) {
                if (!mch[i]) {
                    q.push(i);
                    dis[i] = 1;
                }
            }

            while (q.size()) {
                int u = q.front();
                q.pop();

                if (dis[u] > mx_dis) break;

                for (auto & v : adj[u]) {
                    if (dis[v] == 1e9) {
                        dis[v] = dis[u] + 1;
                        if (!mch[v]) {
                            mx_dis = dis[v];
                        } else {
                            dis[mch[v]] = dis[v] + 1;
                            q.push(mch[v]);
                        }
                    }
                }
            }
            if (mx_dis == 1e9) break;
            fill(vis.begin() + n + 1, vis.end(), 0);

            for (int i = 1; i <= n; i++) {
                auto dfs = [&](auto & dfs, int u) -> bool {
                    for (auto & v : adj[u]) {
                        if (vis[v] || dis[v] != dis[u] + 1) continue;
                        vis[v] = 1;
                        if (mch[v] && dis[v] == mx_dis) continue;
                        if (!mch[v] || dfs(dfs, mch[v])) {
                            mch[u] = v, mch[v] = u;
                            return true;
                        }
                    }
                    return false;
                };
                if (!mch[i]) {
                    ans += dfs(dfs, i);
                }
            }
        }

        return ans;
    } (n, n);

    int cnt1 = 0, cnt2 = 0;

    vector<int> vis(2 * n + 1);

    auto dfs = [&](auto & dfs, int u, int op) -> void {
        if (vis[u]) return;
        vis[u] = 1;
        if (!op) {
            cnt1 += 1 <= u && u <= n;
        } else {
            cnt2 += n + 1 <= u && u <= 2 * n;
        }
        for (auto & v : adj[u]) {
            if (!op) {
                if (1 <= u && u <= n && v == mch[u]) continue;
                if (n + 1 <= u && u <= n + n && v != mch[u]) continue;
            } else {
                if (1 <= u && u <= n && v != mch[u]) continue;
                if (n + 1 <= u && u <= n + n && v == mch[u]) continue;
            }
            dfs(dfs, v, op);
        }
    };

    for (int i = 1; i <= n + n; i++) {
        if (!mch[i]) {
            dfs(dfs, i, (n + 1 <= i && i <= 2 * n));
        }
    }

    cout << cnt1 * cnt2 << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    QWQ();

    while (t--) {
        QAQ();
    }
}