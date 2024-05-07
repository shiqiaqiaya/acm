#include <bits/stdc++.h>
using namespace std;
// #define int long long

mt19937 rd(time(0));

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    vector adj(n + 1, vector<int>());

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    auto ta = a;
    sort(ta.begin() + 1, ta.end());
    ta.erase(unique(ta.begin() + 1, ta.end()), ta.end());
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(ta.begin() + 1, ta.end(), a[i]) - ta.begin();
    }
    int m = ta.size();

    vector<unsigned long long> base(m + 1);

    for (auto & x : base) {
        x = rd();
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }

    vector<int> fa, sz, big, dfn, dep, top;  //top为链顶

    a = [&](int n, int rt, int totdfn = 0) {    //返回用dfn映射后的权值a
        fa = big = dfn = dep = top = vector<int>(n + 1), sz = vector<int>(n + 1, 1);
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
            dfn[u] = ++totdfn, dep[u] = dep[fa[u]] + 1, top[u] = hi, ta[dfn[u]] = a[u];
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

    auto query_path = [&](int u, int v = 0) {
        vector<array<int, 2>> res;
        if (v) {    //查询树上路径
            for ( ; top[u] != top[v]; u = fa[top[u]]) { //先top[u]和top[v]
                if (dep[top[u]] < dep[top[v]]) swap(u, v);
                res.push_back({dfn[top[u]], dfn[u]});
            }
            if (dep[u] < dep[v]) swap(u, v);    //然后才是u和v
            res.push_back({dfn[v], dfn[u]});
        } else {    //查询子树
            res.push_back({dfn[u], dfn[u] + sz[u] - 1});
        }
        return res;
    };

    int q;
    cin >> q;

    vector<array<vector<array<int, 2>>, 2>> tmp(q + 1);

    for (int i = 1; i <= q; i++) {
        int u, v, k;
        cin >> u >> v;
        auto path1 = query_path(u, v);
        cin >> u >> v >> k;
        auto path2 = query_path(u, v);
        tmp[i] = {path1, path2};
    }

    vector<int> ans(q + 1);
    vector mp(m + 1, vector<int>());
    vector<unsigned long long> hash(n + 1);

    for (int i = 1; i <= n; i++) {
        mp[a[i]].push_back(i);
    }

    int B = sqrt(ta.size());
    for (int L = 1; L <= ta.size(); L += B) {
        int R = min(L + B - 1, m);

        hash[0] = 0;

        for (int i = 1; i <= n; i++) {
            hash[i] = hash[i - 1] + (L <= a[i] && a[i] <= R) * base[a[i]];
        }

        for (int i = 1; i <= q; i++) {
            if (ans[i]) {
                continue;
            }
            [&]() {
                auto & [path1, path2] = tmp[i];
                unsigned long long t1 = 0, t2 = 0;
                for (auto & [l, r] : path1) {
                    t1 += hash[r] - hash[l - 1];
                }
                for (auto & [l, r] : path2) {
                    t2 += hash[r] - hash[l - 1];
                }
                if (t1 != t2) {
                    for (int o = L; o <= R; o++) {
                        int cnt1 = 0, cnt2 = 0;
                        for (auto & [l, r] : path1) {
                            cnt1 += upper_bound(mp[o].begin(), mp[o].end(), r) - lower_bound(mp[o].begin(), mp[o].end(), l);
                        }
                        for (auto & [l, r] : path2) {
                            cnt2 += upper_bound(mp[o].begin(), mp[o].end(), r) - lower_bound(mp[o].begin(), mp[o].end(), l);
                        }
                        if (cnt1 != cnt2) {
                            ans[i] = ta[o];
                            return;
                        }
                    }
                    return;
                }
            } ();
        }
    }

    for (int i = 1; i <= q; i++) {
        if (ans[i]) {
            cout << 1 << " " << ans[i] << "\n";
        } else {
            cout << 0 << "\n";
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