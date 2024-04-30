#include <bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, k;
    cin >> n >> k;

    vector<array<int, 2>> a(n + 1);

    multiset<int, greater<>> s_b;
    multiset<int> s_t;
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i][0];
        if (s_b.size() < k) {
            s_b.insert(a[i][0]);
            sum += a[i][0];
        } else {
            if (s_b.size() && a[i][0] < *s_b.begin()) {
                s_t.insert(*s_b.begin());
                sum -= *s_b.begin();
                s_b.erase(s_b.begin());
                s_b.insert(a[i][0]);
                sum += a[i][0];
            } else {
                s_t.insert(a[i][0]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i][1];
    }

    sort(a.begin() + 1, a.end(), [&](const auto & x, const auto & y) {
        return x[1] < y[1] || x[1] == y[1] && x[0] < y[0];
    });

    int ans = 0, now = 0;

    for (int i = 1; i <= n; i++) {
        auto it = s_t.find(a[i][0]);
        if (it != s_t.end()) {
            s_t.erase(it);
        } else {
            it = s_b.find(a[i][0]);
            if (it != s_b.end()) {
                sum -= *it;
                s_b.erase(it);
                if (s_t.size()) {
                    s_b.insert(*s_t.begin());
                    sum += *s_t.begin();
                    s_t.erase(s_t.begin());
                }
            }
        }
        if (s_b.size() < k) {
            break;
        }
        if (a[i][1] > a[i][0]) {
            now += a[i][1] - a[i][0];
        }
        ans = max(ans, now - sum);
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