#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n;
    cin >> n;

    struct nod {
        string s;
        int p, t;
    };

    vector<nod> a(n + 1), b;
    set<int, function<bool(int, int)>> s1([&](const auto & x, const auto & y) {
        return a[x].p > a[y].p || a[x].p == a[y].p && a[x].t < a[y].t;
    }), s2([&](const auto & x, const auto & y) {
        return b[x].p > b[y].p || b[x].p == b[y].p && b[x].t < b[y].t;
    });

    for (int i = 1; i <= n; i++) {
        cin >> a[i].s >> a[i].p >> a[i].t;
        s1.insert(i);
    }
    int m;
    cin >> m;
    b = vector<nod>(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> b[i].s >> b[i].p >> b[i].t;
        s2.insert(i);
    }

    auto F = [&](auto a, auto b, auto s1, auto s2) {
        map<string, int> mp;

        for (auto x : s2) {
            mp[b[x].s] = 1;
        }
        int ans = 1;

        for (auto it = s1.begin(); it != s1.end(); it = next(it)) {
            auto x = *it;
            if (mp[a[x].s]) {

            } else {
                ans++;
            }
            if (a[x].s == "lzr010506") {
                break;
            }
        }

        return ans;
    };

    cout << min(F(a, b, s1, s2), F(b, a, s2, s1)) << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;

    while (t--) {
        QAQ();
    }
}