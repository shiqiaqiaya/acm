#include<bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n, rt, t0;
    cin >> n;

    vector adj(n + 1, vector<array<int, 2>>());

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back({v, 1}), adj[v].push_back({u, 1});
    }

    cin >> rt >> t0;

    vector<int> dep;
    vector<vector<int>> fa, cost;

    [&](int n, int rt) {
        int B = log2(n) + 1;
        dep = vector<int>(n + 1);
        fa = cost = vector(n + 1, vector<int>(B + 1));
        auto dfs = [&](auto & dfs, int u) -> void {
            dep[u] = dep[fa[u][0]] + 1;
            for (int i = 1; i < fa[u].size(); i++) {	//倍增算出父亲
                fa[u][i] = fa[fa[u][i - 1]][i - 1], cost[u][i] = cost[fa[u][i - 1]][i - 1] + cost[u][i - 1];
            }
            for (auto & [v, w] : adj[u]) {	//dfs
                if (v == fa[u][0]) continue;
                fa[v][0] = u, cost[v][0] = w;	//记录
                dfs(dfs, v);
            }
        };

        dfs(dfs, rt);	//源点
    } (n, rt);

    auto lca = [&](int x, int y, int ans = 0) {
        if (dep[x] < dep[y]) swap(x, y);
        for (int h = dep[x] - dep[y], j = 0; h; j++, h >>= 1) {	//上升至同一深度
            if (h & 1) {
                ans += cost[x][j], x = fa[x][j];	//一定！！！要让ans在前,否则x已经改变
            }
        }
        for (int j = fa[x].size() - 1; j >= 0 && x != y; j--) {
            if (fa[x][j] != fa[y][j]) {
                ans += cost[x][j], ans += cost[y][j];
                x = fa[x][j], y = fa[y][j];	//一定！！！要让ans在前,否则x已经改变
            }
        }
        return x == y ? array{ans, x} : array{ans + cost[x][0] + cost[y][0], fa[x][0]};
    };

    vector<int> ans(n + 1, 2 * n + 1);
    int lst_k = n + 1;
    array<int, 2> p = {rt, rt};

    vector mp(2 * n + 2, vector<int>());

    for (int i = 1; i <= n; i++) {
        mp[dep[i]].push_back(i);
    }

    for (int t = 1; t <= 2 * n + 1; t++) {
        for (auto & x : mp[t]) {
            int len = lca(p[0], p[1])[0];
            if (lca(p[0], x)[0] > len) {
                p = {p[0], x};
            } else if (lca(x, p[1])[0] > len) {
                p = {x, p[1]};
            }
        }
        if (t - 1 > t0) {
            int d = lca(p[0], p[1])[0] + 1 >> 1;
            int k = ceil(1.0 * d / (t - 1 - t0));
            for (int o = k; o < lst_k; o++) {
                ans[o] = t - 1;
            }
            lst_k = min(lst_k, k);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
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