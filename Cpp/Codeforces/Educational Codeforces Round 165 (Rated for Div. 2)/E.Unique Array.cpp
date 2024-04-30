#include <bits/stdc++.h>
using namespace std;
#define int long long


void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    struct node {
        int l, r;
        int sum = 0, add = 0;	//需要赋初值，赋为幺元
    };

    vector<node> tr;

    auto merge = [&](node l, node r, node u = {}) { //合并贡献
        u = {l.l, r.r, min(l.sum, r.sum), u.add}; 	//记得补全
        return u;
    };

    auto pushup = [&](int p) {
        tr[p] = merge(tr[p << 1], tr[p << 1 | 1], tr[p]);   //向上传
    };  

    auto add_down = [&](int k, int p) {  //加法的更新
        tr[p].add += k;
        tr[p].sum += k;
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
                return;
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

    int ans = 0;

    map<int, vector<int>> mp;

    for (int i = 1; i <= n; i++) {
        int ok = 0;
        if (!mp[a[i]].size()) {
            update(update, 1, i, 1);
        } else if (mp[a[i]].size() == 1) {
            update(update, 1, mp[a[i]].back(), -1);
            update(update, mp[a[i]].back() + 1, i, 1);
            if (query(query, 1, i).sum <= 0) {
                ok = 1;
                ans++;
                update(update, 1, mp[a[i]].back(), 1);
                update(update, 1, i, 1);
            }
        } else {
            update(update, mp[a[i]][mp[a[i]].size() - 2] + 1, mp[a[i]].back(), -1);
            update(update, mp[a[i]].back() + 1, i, 1);
            if (query(query, 1, i).sum <= 0) {
                ok = 1;
                ans++;
            update(update, mp[a[i]][mp[a[i]].size() - 2] + 1, mp[a[i]].back(), 1);
                update(update, 1, i, 1);
            }
        }

        if (!ok) {
            mp[a[i]].push_back(i);
        }
    }

    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}