#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, q;
    cin >> n;

    vector<int> a(n + 1);
    vector adj(n + 1, vector<int>());

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> fa, sz, big, dfn, dfn_node, dep, top;  //top为链顶

    a = [&](int n, int rt, int totdfn = 0) {    //返回用dfn映射后的权值a
        fa = big = dfn = dep = top = dfn_node = vector<int>(n + 1), sz = vector<int>(n + 1, 1);
        vector<int> ta(n + 1);

        auto dfs0 = [&](auto & dfs0, int u) -> void {   //这里最好只预处理sz, big和fa,因为搜索顺序需要按dfs的而不是dfs0
            for (auto & v : adj[u]) {
                if (v == fa[u]) continue;
                fa[v] = u, dfs0(dfs0, v);
                sz[u] += sz[v];
                if (!big[u] || sz[big[u]] < sz[v]) {
                    big[u] = v;
                }
            }
        };

        auto dfs = [&](auto & dfs, int u, int hi) -> void {  //先搜重儿子,记录top,必须在此处计算dfn才是对的
            dfn[u] = ++totdfn, dfn_node[totdfn] = u, dep[u] = dep[fa[u]] + 1, top[u] = hi, ta[dfn[u]] = a[u];
            if (!big[u]) return;
            dfs(dfs, big[u], hi);
            for (auto & v : adj[u]) {
                if (v == fa[u] || v == big[u]) continue;
                dfs(dfs, v, v);
            }
        };

        dfs0(dfs0, rt), dfs(dfs, rt, rt);

        return ta;
    } (n, 1);

    auto lca = [&](int u, int v) {
        for ( ; top[u] != top[v]; u = fa[top[u]]) { //先top[u]和top[v]
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
        }
        return dep[u] < dep[v] ? u : v;
    };

    auto jump = [&](int u, int k) {
        if (dep[u] < k) {
            return (int)-1;
        }
        int d = dep[u] - k;
        while (dep[top[u]] > d) {
            u = fa[top[u]];
        }
        return dfn_node[dfn[u] - dep[u] + d];
    };

    cin >> q;
    vector<int> ans(q + 1);
    vector<array<int, 3>> que(q + 1);

    for (int i = 1; i <= q; i++) {
        cin >> que[i][0] >> que[i][1];
        que[i][2] = lca(que[i][0], que[i][1]);
    }

    for (int bit = 20; ~bit; bit--) {
        vector<array<int, 2>> f(n + 1);
        auto dfs = [&](auto && dfs, int u) -> void {
            f[u][1] = f[u][0] = f[fa[u]][0] + (a[dfn[u]] >> bit & 1);
            if (dep[u] - dep[1] >= (1ll << bit)) {
                f[u][1] = (f[u][0] - f[jump(u, 1ll << bit)][0]) + (dep[jump(u, 1ll << bit)] - f[jump(u, 1ll << bit)][1]);
            }
            for (auto & v : adj[u]) {
                if (v == fa[u]) continue;
                dfs(dfs, v);
            }
        };

        dfs(dfs, 1);

        for (int i = 1; i <= q; i++) {
            auto [x, y, lca] = que[i];
            int t = dep[x] - dep[lca] + 1, tx = x, ty = y;
            int r = t % (1ll << bit), q = (t - r) / (1ll << bit);
            int q1 = q;
            tx = jump(tx, t - r);
            if (q & 1) {
                ans[i] += f[x][1] - (dep[tx] - f[tx][1]) << bit;
                ans[i] += (dep[tx] - dep[lca] + 1) - (f[tx][0] - f[fa[lca]][0]) << bit;
            } else {
                ans[i] += f[x][1] - f[tx][1] << bit;
                ans[i] += f[tx][0] - f[fa[lca]][0] << bit;
            }
            t = dep[x] + dep[y] - 2 * dep[lca] + 1, r = t % (1ll << bit), q = (t - r) / (1ll << bit);
            if (q > q1) {
                ty = jump(ty, r);
                if (q & 1) {
                    ans[i] += (dep[y] - dep[ty]) - (f[y][0] - f[ty][0]) << bit;
                } else {
                    ans[i] += f[y][0] - f[ty][0] << bit;
                }
            }
            y = ty;
            if (q > q1 + 1) {
                ty = jump(ty, (q - q1 - 1) * (1ll << bit));
                if (q & 1) {
                    ans[i] += f[y][1] << bit;
                } else {
                    ans[i] += dep[y] - f[y][1] << bit;
                }
                if (q1 + 1 & 1) {
                    ans[i] -= f[ty][1] << bit;
                } else {
                    ans[i] -= (dep[ty] - f[ty][1]) << bit;
                }
            }
            if (q1 & 1) {
                ans[i] += (dep[ty] - dep[lca]) - (f[ty][0] - f[lca][0]) << bit;
            } else {
                ans[i] += f[ty][0] - f[lca][0] << bit;
            }
        }
    }

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << "\n";
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