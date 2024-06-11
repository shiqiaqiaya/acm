#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, l, p;
    cin >> n >> l >> p;

    vector<string> str(n + 1);
    vector<int> s(n + 1), ans(n + 1);
    vector<long double> dp(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> str[i];
        s[i] = s[i - 1] + str[i].size();
    }

    deque<array<int, 3>> q = {{0, 1, n}};


    for (int i = 1; i <= n; i++) {
        auto get = [&](int j, int i) {
            long double res = 1;
            int t = abs((s[i] - s[j]) + (i - j - 1) - l);

            for (int i = 1; i <= p; i++) {
                (res *= t);
            }
            return dp[j] + res;
        };

        dp[i] = get(q[0][0], i), ans[i] = q[0][0];
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

    stack<string> res;

    if (dp[n] > 1e18) {
        cout << "Too hard to arrange\n" << string(20, '-') << "\n";
        return;
    }

    cout << (int)dp[n] << "\n";

    for (int i = n; i; i = ans[i]) {
        string t = str[ans[i] + 1];
        for (int j = ans[i] + 2; j <= i; j++) {
            t += " " + str[j];
        }
        res.push(t);
    }

    while (res.size()) {
        cout << res.top() << "\n";
        res.pop();
    }

    cout << string(20, '-') << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}