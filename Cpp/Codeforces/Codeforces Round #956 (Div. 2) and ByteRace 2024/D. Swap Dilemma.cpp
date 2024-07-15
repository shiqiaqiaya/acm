#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    if (multiset(a.begin(), a.end()) != multiset(b.begin(), b.end())) {
        cout << "No\n";
        return;
    }

    auto init = [&](vector<int> & a) {
        auto ta = a;
        sort(ta.begin(), ta.end());
        ta.erase(unique(ta.begin(), ta.end()), ta.end());

        for (int i = 1; i <= n; i++) {
            a[i] = lower_bound(ta.begin(), ta.end(), a[i]) - ta.begin();
        }
    };

    init(a), init(b);

    auto F = [&](vector<int> & a, int ans = 0) {
        vector<int> tr(n + 1);

        auto lowbit = [&](int x) {
            return x & -x;
        };

        auto add = [&](int x, int k) {
            for ( ; x < tr.size(); x += lowbit(x)) {
                tr[x] += k;
            }
        };

        auto get = [&](int x, int res = 0) {
            for ( ; x; x -= lowbit(x)) {
                res += tr[x];
            }
            return res;
        };

        for (int i = 1; i <= n; i++) {
            ans += get(n) - get(a[i]);
            add(a[i], 1);
        }

        return ans;
    };

    if (F(a) % 2 != F(b) % 2) {
        cout << "No\n";
        return;
    }

    cout << "YES\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}