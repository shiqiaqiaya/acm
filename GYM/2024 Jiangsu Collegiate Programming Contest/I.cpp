#include<bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n;
    cin >> n;

    vector<array<int, 2>> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i][0];
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i][1];
    }

    int l = 1, r = 1e9;

    auto chk = [&](int mid) {
        array<multiset<int>, 2> t;


        for (int i = 1; i <= n; i++) {
            if (t[a[i][1] ^ 1].size()) {
                auto it = t[a[i][1] ^ 1].lower_bound(mid - a[i][0]);

                if (it == t[a[i][1] ^ 1].end()) {
                    return 0;
                } else {
                    t[a[i][1] ^ 1].erase(it);
                }
            } else {
                t[a[i][1]].insert(a[i][0]);
            }
        }

        return 1;
    };

    while (l < r) {
        int mid = l + r + 1 >> 1;

        if (chk(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << l << "\n";
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