#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1ll << 21;

void QAQ() {
    int q, now = 0;
    cin >> q;

    vector<array<int, 21>> tr(mod + 1);

    auto lowbit = [&](int x) {
        return x & -x;
    };
    auto add = [&](int x, int k, int pos) {
        for (x++; x < tr.size(); x += lowbit(x)) {
            tr[x][pos] += k;
        }
    };
    auto get = [&](int x, int pos, int res = 0) {
        for (x = min(x + 1, (int)tr.size() - 1); x; x -= lowbit(x)) {
            res += tr[x][pos];
        }
        return res;
    };

    auto insert = [&](int x) {
        for (int bit = 20; ~bit; bit--) {
            int t_mod = 1ll << bit + 1;
            add((-x % t_mod + t_mod) % t_mod, 1, bit);
        }
    };
    auto del = [&](int x) {
        for (int bit = 20; ~bit; bit--) {
            int t_mod = 1ll << bit + 1;
            add((-x % t_mod + t_mod) % t_mod, -1, bit);
        }
    };

    auto get_ans = [&](int now, int res = 0) {
        for (int bit = 20; ~bit; bit--) {
            int t_mod = 1ll << bit + 1;
            int x = now % t_mod, cnt = 0;
            int t1 = max(0ll, (1ll << bit) - x), t2 = t_mod - 1 - x;
            if (t1 <= t2) {
                cnt += get(t2, bit) - get(t1 - 1, bit);
            }
            t1 = max(t_mod - x, t_mod + (1ll << bit) - x), t2 = mod;
            if (t1 <= t2) {
                cnt += get(t2, bit) - get(t1 - 1, bit);
            }
            if (cnt & 1) {
                res |= 1ll << bit;
            }
        }
        return res;
    };

    vector<int> a;

    for (int i = 1; i <= q; i++) {
        int t, v;
        cin >> t >> v;
        while (t--) {
            now -= a.back();
            del(now);
            a.pop_back();
        }
        insert(now);
        a.push_back(v);
        now += v;
        cout << get_ans(now) << "\n";
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