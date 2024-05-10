#include <bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int r, c;
    cin >> r >> c;

    vector<string> a(r + 1);
    vector<vector<int>> mp(c + 1);

    for (int i = 1; i <= r; i++) {
        cin >> a[i];
        a[i] = " " + a[i];
    }

    vector<int> fa(2 * r + 1);
    iota(fa.begin(), fa.end(), 0);

    auto find = [&](auto & find, int u) -> int {
        return fa[u] == u ? u : fa[u] = find(find, fa[u]);
    };

    auto merge = [&](int u, int v) {
        int fu = find(find, fa[u]), fv = find(find, fa[v]);
        if (fu != fv) {
            fa[fu] = fv;
        }
    };

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (a[i][j] == '1') {
                for (auto & x : mp[j]) {
                    merge(i, x + r), merge(i + r, x);
                }
                for (auto & x : mp[c - j + 1]) {
                    merge(i, x), merge(i + r, x + r);
                }
                if ((mp[j].size() && a[i][c - j + 1] == '1') || mp[j].size() >= 2) {
                    cout << "0\n";
                    return;
                }
                mp[j].push_back(i);
            }
        }
    }

    set<int> s;
    int cnt = 0;
    for (int i = 1; i <= r; i++) {
        if (find(find, i) == find(find, i + r)) {
            cout << "0\n";
            return;
        }
        s.insert(find(find, i)), s.insert(find(find, i + r));
    }
    int ans = 1;
    const int mod = 1e9 + 7;
    for (int i = 1; i <= s.size() / 2; i++) {
        (ans *= 2) %= mod;
    }

    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    QWQ();

    while (t--) {
        QAQ();
    }
}