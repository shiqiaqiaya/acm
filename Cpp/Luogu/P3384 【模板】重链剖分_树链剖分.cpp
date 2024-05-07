#include <bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, q, rt, mod;
    cin >> n >> q >> rt >> mod;

    vector<int> a(n + 1);   //点权
    vector adj(n + 1, vector<int>());

    vector<int> fa, sz, big, dfn, dep, top;  //top为链顶

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }

    a = [&](int n, int rt, int totdfn = 0) {    //返回用dfn映射后的a
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
    } (n, rt);

    struct node {
        int l, r;
        int sum = 0, add = 0;	//需要赋初值，赋为幺元
    };

    vector<node> tr;

    auto merge = [&](node l, node r, node u = {}) { //合并贡献
        u = {l.l, r.r, (l.sum + r.sum) % mod, u.add}; 	//记得补全
        return u;
    };

    auto pushup = [&](int p) {
        tr[p] = merge(tr[p << 1], tr[p << 1 | 1], tr[p]);   //向上传
    };

    auto add_down = [&](int k, int p) {  //加法的更新
        (tr[p].add += k) %= mod, (tr[p].sum += (tr[p].r - tr[p].l + 1) * k) %= mod;
    };

    auto pushdown = [&](int p) {    //add标记下传，若有乘法和加法，先计算乘法标记，且乘法标记会对加法标记有影响
        add_down(tr[p].add, p << 1), add_down(tr[p].add, p << 1 | 1);
        tr[p].add = 0;
    };

    [&](int sz) {  //建树
        tr = vector<node>(sz << 2);

        auto build = [&](auto & build, int l, int r, int p = 1) {
            tr[p] = {l, r};
            if (l == r) {
                (tr[p].sum = a[r]) %= mod;
                return; //到达叶子节点
            }
            pushdown(p);    //可不用
            int mid = l + r >> 1;
            build(build, l, mid, p << 1), build(build, mid + 1, r, p << 1 | 1);
            pushup(p);
        };

        build(build, 1, sz);
    } (n);

    auto update = [&](auto & update, int l, int r, int k, int p = 1) {    //更新
        if (l <= tr[p].l && tr[p].r <= r) {
            add_down(k, p); //添加标记,更新节点
            return;
        }
        pushdown(p);
        if (l <= tr[p << 1].r) update(update, l, r, k, p << 1); //左边有交集
        if (tr[p << 1 | 1].l <= r) update(update, l, r, k, p << 1 | 1); //右边有交集
        pushup(p);
    };

    auto query = [&](auto & query, int l, int r, int p = 1) -> node {
        if (l <= tr[p].l && tr[p].r <= r) { //被包含
            return tr[p];
        }
        pushdown(p);
        if (r <= tr[p << 1].r) return query(query, l, r, p << 1);   //只在左边
        if (tr[p << 1 | 1].l <= l) return query(query, l, r, p << 1 | 1);   //只在右边
        return merge(query(query, l, r, p << 1), query(query, l, r, p << 1 | 1));   //左右都有
        pushup(p);  //可不用
    };

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

    for (int i = 1, op, x, y, z; i <= q; i++) {
        cin >> op >> x;
        switch (op) {
            case 1 : {
                cin >> y >> z;
                auto path = query_path(x, y);
                for (auto & [l, r] : path) {
                    update(update, l, r, z %= mod);
                }
                break;
            } case 2 : {
                cin >> y;
                auto path = query_path(x, y);
                int res = 0;
                for (auto & [l, r] : path) {
                    (res += query(query, l, r).sum) %= mod;
                }
                cout << res << "\n";
                break;
            } case 3 : {
                auto path = query_path(x);
                cin >> z;
                for (auto & [l, r] : path) {
                    update(update, l, r, z %= mod);
                }
                break;
            } default : {
                auto path = query_path(x);
                int res = 0;
                for (auto & [l, r] : path) {
                    (res += query(query, l, r).sum) %= mod;
                }
                cout << res % mod << "\n";
                break;
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