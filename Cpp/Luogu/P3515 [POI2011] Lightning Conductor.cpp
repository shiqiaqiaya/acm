#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<double> dp(n + 1);

    auto F = [&]() {
        deque<array<int, 3>> q = {{1, 1, n}};
        for (int i = 2; i <= n; i++) {
            auto get = [&](int j, int i) {
                return a[i] - a[j] - sqrt(i - j);
            };
            dp[i] = min(dp[i], get(q[0][0], i));
            q[0][1] = i + 1;
            if (q[0][1] > q[0][2]) {
                q.pop_front();
            }

            auto insert = [&](int i) {
                int pos = n + 1;
                while (q.size() && get(q.back()[0], q.back()[1]) >= get(i, q.back()[1])) {
                    pos = q.back()[1];
                    q.pop_back();
                }
                if (q.size() && get(q.back()[0], q.back()[2]) >= get(i, q.back()[2])) {
                    auto [j, l, r] = q.back();
                    while (l < r) {
                        int mid = l + r >> 1;
                        if (get(j, mid) >= get(i, mid)) {
                            r = mid;
                        } else {
                            l = mid + 1;
                        }
                    }
                    q.back()[2] = r - 1;
                    pos = r;
                }
                if (pos <= n) {
                    q.push_back({i, pos, n});
                }
            };

            insert(i);
        }
    };


    F();
    reverse(a.begin() + 1, a.end()), reverse(dp.begin() + 1, dp.end());
    F();
    reverse(a.begin() + 1, a.end()), reverse(dp.begin() + 1, dp.end());
    for (int i = 1; i <= n; i++) {
        cout << (int)floor(-dp[i]) << "\n";
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