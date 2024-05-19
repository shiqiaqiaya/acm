#include <bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n;
    cin >> n;

    vector<array<int, 3>> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }

    sort(a.begin() + 1, a.end(), [&](auto & x, auto & y) {
        return x[0] < y[0] || x[0] == y[0] && x[1] > y[1];
    });

    int mx = a.back()[1];

    vector<array<int, 3>> ans;

    for (int i = n; i; i--) {
        if (a[i][1] > mx) {
            
        } else {
            ans.push_back(a[i]);
        }
        mx = min(mx, a[i][1]);
    }

    sort(ans.begin(), ans.end(), [&](auto & x, auto & y) {
        return x[2] < y[2];
    });

    cout << ans.size() << "\n";

    for (auto & x : ans) {
        cout << x[2] << " ";
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