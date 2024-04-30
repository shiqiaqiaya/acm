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

    auto update_path = [&](int u, int v, int k) {   //树链剖分路径加k
        while (top[u] != top[v]) {  //这里是top[u]和top[v]
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            update(update, dfn[top[u]], dfn[u], k);
            u = fa[top[u]];
        }
        if (dep[u] < dep[v]) swap(u, v);    //这里是u和v
        update(update, dfn[v], dfn[u], k);
    };

    auto update_tree = [&](int u, int k) {  //子树加k
        update(update, dfn[u], dfn[u] + sz[u] - 1, k);  //子树可以这么表达
    };

    auto query_path = [&](int u, int v) {   //树链剖分查路径和
        node res = {0, max(dfn[u], dfn[v]), 0, 0};
        while (top[u] != top[v]) {  //先top[u]和top[v]
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            res = merge(query(query, dfn[top[u]], dfn[u]), res);
            u = fa[top[u]];
        }
        if (dep[u] < dep[v]) swap(u, v);    //然后才是u和v
        return merge(query(query, dfn[v], dfn[u]), res);
    };

    auto query_tree = [&](int u) {
        return query(query, dfn[u], dfn[u] + sz[u] - 1);
    };

    for (int i = 1, op, x, y, z; i <= q; i++) {
        cin >> op >> x;
        switch (op) {
            case 1 : {
                cin >> y >> z;
                update_path(x, y, z %= mod);
                break;
            } case 2 : {
                cin >> y;
                cout << query_path(x, y).sum % mod << "\n";
                break;
            } case 3 : {
                cin >> z;
                update_tree(x, z %= mod);
                break;
            } default : {
                cout << query_tree(x).sum % mod << "\n";
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