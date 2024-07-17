#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, q;
    array<int, 2> m;
    cin >> m[0] >> m[1] >> n >> q;
    vector<pair<char, int>> a(n + 1);
    vector<array<int, 2>> pre(n + 1), abs_pre(n + 1), s(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    struct node {
        int l, r;
        array<int, 2> mn = {(const int)4e18, (const int)4e18}, mx = {(const int)-4e18, (const int)-4e18};
    };

    vector<node> tr;

    auto merge = [&](node l, node r, node u = {}) { //合并贡献
        u = {l.l, r.r, {min(l.mn[0], r.mn[0]), min(l.mn[1], r.mn[1])}, {max(l.mx[0], r.mx[0]), max(l.mx[1], r.mx[1])}}; 	//记得补全
        return u;
    };

    auto pushup = [&](int p) {
        tr[p] = merge(tr[p << 1], tr[p << 1 | 1], tr[p]);   //向上传
    };

    [&](int sz) {  //建树
        tr = vector<node>(sz << 2);
        array<int, 2> now = {0, 0}, abs_now = {0, 0};

        auto build = [&](auto & build, int l, int r, int p = 1) {
            tr[p] = {l, r};
            if (l == r) {
                switch (a[l].first) {
                    case 'U' : {
                        now[1] += a[l].second;
                        s[l][1] += a[l].second;
                        abs_now[1] += a[l].second;
                        break;
                    } case 'D' : {
                        now[1] -= a[l].second;
                        s[l][1] -= a[l].second; 
                        abs_now[1] += a[l].second;
                        break;
                    } case 'L' : {
                        now[0] -= a[l].second;
                        s[l][0] -= a[l].second;
                        abs_now[0] += a[l].second;
                        break;
                    } case 'R' : {
                        now[0] += a[l].second;
                        s[l][0] += a[l].second;
                        abs_now[0] += a[l].second;
                        break;
                    }
                }
                abs_pre[l] = abs_now;
                pre[l] = tr[p].mn = tr[p].mx = now;
                return; //到达叶子节点
            }
            int mid = l + r >> 1;
            build(build, l, mid, p << 1), build(build, mid + 1, r, p << 1 | 1);
            pushup(p);
        };

        build(build, 1, sz);
    } (n);

    auto query_non = [&](auto & query_non, int l, int r, int p = 1) -> node {
        if (l <= tr[p].l && tr[p].r <= r) { //被包含
            return tr[p];
        }
        if (r <= tr[p << 1].r) return query_non(query_non, l, r, p << 1);   //只在左边
        if (tr[p << 1 | 1].l <= l) return query_non(query_non, l, r, p << 1 | 1);   //只在右边
        return merge(query_non(query_non, l, r, p << 1), query_non(query_non, l, r, p << 1 | 1));   //左右都有
    };

    auto query_nxt = [&](auto & query_nxt, int x, int l, int r, int op, int p = 1) -> node {
        if (l <= tr[p].l && tr[p].r <= r && 0 <= x + tr[p].mn[op] - pre[l - 1][op] && x + tr[p].mx[op] - pre[l - 1][op] <= m[op]) {
            return tr[p];
        }
        if (tr[p].l == tr[p].r) {
            return tr[p];
        }
        if (r <= tr[p << 1].r) return query_nxt(query_nxt, x, l, r, op, p << 1);
        if (tr[p << 1 | 1].l <= l) return query_nxt(query_nxt, x, l, r, op, p << 1 | 1);
        auto tmp = query_nxt(query_nxt, x, l, r, op, p << 1);
        if (x + tmp.mn[op] - pre[l - 1][op] < 0 || x + tmp.mx[op] - pre[l - 1][op] > m[op]) {
            return tmp;
        }
        return query_nxt(query_nxt, x, l, r, op, p << 1 | 1);
    };

    vector<array<array<int, 20>, 2>> nxt(2 * n + 1), cost(2 * n + 1);

    for (int i = n - 1; i; i--) {
        for (auto op : {0, 1}) {
            auto tmp = query_non(query_non, i + 1, n);
            if (0 > tmp.mn[op] - pre[i][op] || tmp.mx[op] - pre[i][op] > m[op]) {
                int r = query_nxt(query_nxt, 0, i + 1, n, op).r;
                int tx = pre[r - 1][op] - pre[i][op];
                cost[2 * i - 1][op][0] = abs_pre[r - 1][op] - abs_pre[i][op];
                if (s[r][op] < 0) {
                    nxt[2 * i - 1][op][0] = 2 * r - 1;
                    cost[2 * i - 1][op][0] += tx;
                } if (s[r][op] > 0) {
                    nxt[2 * i - 1][op][0] = 2 * r;
                    cost[2 * i - 1][op][0] += m[op] - tx;
                }
            } if (0 > m[op] + tmp.mn[op] - pre[i][op] || tmp.mx[op] - pre[i][op] > 0) {
                int r = query_nxt(query_nxt, m[op], i + 1, n, op).r;
                int tx = m[op] + pre[r - 1][op] - pre[i][op];
                cost[2 * i][op][0] = abs_pre[r - 1][op] - abs_pre[i][op];
                if (s[r][op] < 0) {
                    nxt[2 * i][op][0] = 2 * r - 1;
                    cost[2 * i][op][0] += tx;
                } else if (s[r][op] > 0) {
                    nxt[2 * i][op][0] = 2 * r;
                    cost[2 * i][op][0] += m[op] - tx;
                }
            }
            for (auto st : {2 * i - 1, 2 * i}) {
                for (int j = 1; j < nxt[st][op].size(); j++) {
                    if (nxt[st][op][j - 1] && nxt[nxt[st][op][j - 1]][op][j - 1]) {
                        nxt[st][op][j] = nxt[nxt[st][op][j - 1]][op][j - 1];
                        cost[st][op][j] = cost[st][op][j - 1] + cost[nxt[st][op][j - 1]][op][j - 1];
                    }
                }
            }
        }
    }

    while (q--) {
        int x, y, l, r, ans = 0, tx, ty;
        cin >> x >> y >> l >> r;

        auto F = [&](int x, int op, int & tx) {
            int res = 0;
            auto tmp = query_non(query_non, l, r);
            if (0 <= x + tmp.mn[op] - pre[l - 1][op] && x + tmp.mx[op] - pre[l - 1][op] <= m[op]) {
                tx = x + pre[r][op] - pre[l - 1][op];
                return abs_pre[r][op] - abs_pre[l - 1][op];
            }
            int tmp_r = query_nxt(query_nxt, x, l, r, op).r, st;
            tx = x + pre[tmp_r - 1][op] - pre[l - 1][op];
            res += abs_pre[tmp_r - 1][op] - abs_pre[l - 1][op];
            if (s[tmp_r][op] < 0) {
                res += tx;
                tx = 0;
                st = 2 * tmp_r - 1;
            } else if (s[tmp_r][op] > 0) {
                res += m[op] - tx;
                tx = m[op];
                st = 2 * tmp_r;
            }
            for (int j = nxt[st][op].size() - 1; ~j; j--) {
                if (nxt[st][op][j] && nxt[st][op][j] <= 2 * r) {
                    res += cost[st][op][j];
                    st = nxt[st][op][j];
                    tmp_r = st + 1 >> 1;
                    if (st & 1) {
                        tx = 0;
                    } else {
                        tx = m[op];
                    }
                }
            }

            tx += pre[r][op] - pre[tmp_r][op];
            res += abs_pre[r][op] - abs_pre[tmp_r][op];

            return res;
        };

        ans += F(x, 0, tx) + F(y, 1, ty);
        cout << tx << " " << ty << " " << ans << "\n";
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