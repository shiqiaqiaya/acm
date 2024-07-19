#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int op, n, m;
    cin >> op >> n >> m;

    vector adj(n + 1, vector<array<int, 2>>());
    vector<int> indu(n + 1);

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        indu[v]++;
        if (op == 1) {
            adj[v].push_back({u, -i});
        }
    }

    auto Euler_circuit = [&](int n, int m, int op) {   // op 为 1 表示双向，为 0 表示单向
        vector<int> vis(m + 1), res;

        for (int i = 1; i <= n; i++) {
            if (op == 1) {
                if (adj[i].size() & 1) {
                    return res = {-1};  // 注意不合法的返回
                }
            } else {
                if (adj[i].size() != indu[i]) {
                    return res = {-1};
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (adj[i].size()) {
                auto dfs = [&](auto & dfs, int u) -> void {
                    while (adj[u].size()) {
                        auto [v, t] = adj[u].back();
                        adj[u].pop_back();
                        int i = abs(t);
                        if (vis[i]) continue;
                        vis[i] = 1;
                        dfs(dfs, v);
                        res.push_back(t);
                    }
                };
                dfs(dfs, i);    // 回溯 push ，为了保证其他环都跑完
                break;
            }
        }
        if (accumulate(vis.begin() + 1, vis.end(), 0) != m) return res = {-1};  //边不联通
        return res = vector(res.rbegin(), res.rend());  // reverse 因为是回溯的时候 push
    } (n, m, op);

    if (Euler_circuit != vector<int>{-1}) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < Euler_circuit.size(); i++) {
        cout << Euler_circuit[i] << " \n"[i + 1 == Euler_circuit.size()];
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