#include<bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 1), ans;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    multiset<int> s(a.begin() + 1, a.end());
    set<int, greater<>> t(a.begin() + 1, a.end());

    for (int i = 1; i <= n; i++) {
        t.insert(a[i] * 2 + 1);
        t.insert(a[i] * 2 - 1);
    }

    auto dfs = [&](auto & dfs, int now) -> int {
        if (s.find(now) != s.end()) {
            s.extract(now);
            return 1;
        }
        if (now % 2 == 0) {
            return 0;
        }
        int a = now / 2, b = now - a;
        if (a & 1) swap(a, b);
        if (!s.count(a)) {
            return 0;
        }
        s.extract(a);
        if (dfs(dfs, b)) {
            return 1;
        } else {
            s.insert(a);
        }
        return 0;
    };

    for (auto & x : t) {
        while (dfs(dfs, x)) {
            ans.push_back(x);
        }
    }

    cout << ans.size() << "\n";

    for (auto & x : ans) {
        cout << x << " ";
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