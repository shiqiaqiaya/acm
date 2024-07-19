#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, m;
    cin >> n >> m;

    vector adj(n + 1, vector<array<int, 2>>());
    vector<int> indu(n + 1);

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        indu[v]++;
    }

    auto [euler_type, euler_path] = [&](int n, int m, int op, vector<vector<array<int, 2>>> adj) {
        vector<int> vis(m + 1), res;    // 有向时不需要 vis, 无向不需要 indu
        int flag = 0;   // 若flag 最后为 0 ，则为欧拉回路
        for (int i = 1; i <= n; i++) {  // adj 最后一维记录的为边的编号
            if (!op && (adj[i].size() & 1)) {
                if (++flag > 2) return pair{(int)-1, res};
            } if (op && adj[i].size() != indu[i]) {
                switch ((int)adj[i].size() - indu[i]) {
                    case 1 : flag += 1; break;
                    case -1 : flag += 3; break;
                    default : return pair{(int)-1, res};
                }
                if (!(flag & 1) && flag != 4) return pair{(int)-1, res};
            }
            sort(adj[i].begin(), adj[i].end(), greater());  // 按字典序从小到大
        }
        for (int i = 1; i <= n; i++) {
            auto dfs = [&](auto & dfs, int u) -> void {
                while (adj[u].size()) {
                    auto [v, i] = adj[u].back();
                    adj[u].pop_back();
                    if (vis[i]) continue;   // 有向时不需要
                    vis[i] = 1;
                    dfs(dfs, v);
                }
                res.push_back(u);   // 回溯 push ，为了保证其他环都跑完
            };
            if (!flag && adj[i].size()) { dfs(dfs, i); break; }
            if (!op && (adj[i].size() & 1)) { dfs(dfs, i); break; }
            if (op && adj[i].size() > indu[i]) { dfs(dfs, i); break; }
        }
        if (accumulate(adj.begin() + 1, adj.end(), 0, [&](auto now, auto & x) { return now + x.size(); })) {
            return pair{(int)-1, res};  // 边不联通
        }
        return pair{flag, vector(res.rbegin(), res.rend())};    // reverse 因为是回溯的时候 push
    } (n, m, 1, adj);

    if (euler_type < 0) {
        cout << "No\n";
        return;
    }

    for (int i = 0; i < euler_path.size(); i++) {
        cout << euler_path[i] << " \n"[i + 1 == euler_path.size()];
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