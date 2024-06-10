#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n;
    cin >> n;

    auto query = [&](int d, int x = 0, int y = 0) {
        cout << "? " << d << endl;
        cin >> x >> y;
        return array{x, y};
    };

    deque<int> ans;

    auto dfs = [&](auto & dfs, int now) -> void {
        if (now == 0) {
            return;
        }
        if (now == 1) {
            ans.push_back(query(0)[0]);
            return;
        }
        auto t = query(now - 2);
        if (t[1]) {
            dfs(dfs, now - 1);
            if (ans.front() == t[1]) {
                ans.push_back(t[0]);
            } else {
                ans.push_front(t[0]);
            }
        } else {
            auto tmp = query(0);
            dfs(dfs, now - 2);
            ans.push_back(t[0]), ans.push_back(tmp[0]);
        }
    };

    dfs(dfs, n);

    cout << "!";

    for (auto & x : ans) {
        cout << " " << x;
    }
    cout << endl;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}