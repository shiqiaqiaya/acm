#include <bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    vector<vector<array<int, 2>>> tmp;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        auto pos = lower_bound(tmp.begin(), tmp.end(), a[i], [&](auto & x, auto & y) {
            return x.back()[0] < y;
        });

        if (pos == tmp.end()) {
            vector<array<int, 2>> _;
            _.push_back({a[i], i});
            tmp.push_back(_);
        } else {
            (*pos).push_back({a[i], i});
        }
    }

    set<int> ans;

    for (int i = tmp.size() - 1; ~i; i--) {
        auto & t = tmp[i];

        vector<array<int, 2>> res;

        for (auto & [x, id] : t) {
            if (i + 1 == tmp.size()) {
                ans.insert(id);
                res.push_back({x, id});
            } else {
                auto it = upper_bound(tmp[i + 1].begin(), tmp[i + 1].end(), id, [&](auto & x, auto & y) {
                    return x < y[1];
                });

                if (it == tmp[i + 1].end() || (*it)[0] <= x) {
                    continue;
                }

                ans.insert(id);
                res.push_back({x, id});
            }
        }

        swap(res, tmp[i]);
    }

    cout << ans.size() << "\n";

    for (auto & x : ans) {
        cout << x << " ";
    }

    cout << "\n";

    vector<array<int, 2>> t;

    array<int, 2> _ = {1, 1};

    t.push_back({1, 1});
    t.emplace_back(_);
    t.emplace_back({1, 1});
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