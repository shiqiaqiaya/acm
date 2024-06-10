#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, d;
    cin >> n >> d;

    vector<array<int, 3>> a(n + 1);
    array<map<int, set<array<int, 2>>>, 2> mp;
    map<array<int, 2>, int> s;

    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1];
        s[{a[i][0], a[i][1]}] = i;
        a[i][2] = i;
        mp[0][a[i][0] + a[i][1]].insert({a[i][1], a[i][2]});
        mp[1][a[i][1] - a[i][0]].insert({a[i][1], a[i][2]});
    }


    vector<array<int, 2>> D = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

    array<int, 3> ans = {0, 0, 0};

    for (int i = 1; i <= n; i++) {
        for (auto & [dx, dy] : D) {
            array<int, 2> t = {a[i][0] + dx * d / 2, a[i][1] + dy * d / 2};
            if (!s.contains(t)) continue;
            int tmp;
            if (dx > 0 && dy > 0) {
                tmp = a[i][1] - a[i][0] + d;
            } else if (dx > 0) {
                tmp = a[i][0] + a[i][1] - d;
            } else if (dy > 0) {
                tmp = a[i][0] + a[i][1] + d;
            } else {
                tmp = a[i][1] - a[i][0] - d;
            }
            auto & ts = mp[dx * dy > 0][tmp];

            if (ts.size()) {
                if (dy > 0) {
                    auto it = ts.lower_bound({a[i][1] + d / 2, 0});
                    if (it != ts.end() && ((dx > 0 && it -> front() - tmp <= a[i][0]) || (dx < 0 && tmp - it -> front() >= a[i][0]))) {
                        ans = {it -> back(), i, s[t]};
                    }
                } else {
                    auto it = ts.lower_bound({a[i][1] - d / 2, (int)1e9});
                    if (it != ts.begin()) {
                        it = prev(it);
                        if ((dx < 0 && it -> front() - tmp >= a[i][0]) || (dx > 0 && tmp - it -> front() <= a[i][0])) {
                            ans = {it -> back(), i, s[t]};
                        }
                    }
                }
            }
        }
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}