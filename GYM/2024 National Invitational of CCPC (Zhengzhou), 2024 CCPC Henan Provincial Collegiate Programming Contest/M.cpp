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

    int l = 0, r = 1e9;

    auto chk = [&](int mid) {
        int mn = -4e9, mx = 4e18;
        for (int i = 1; i <= n; i++) {
            int l = a[i][0] - mid * a[i][1], r = a[i][0] + mid * a[i][1];
            mn = max(l, mn), mx = min(r, mx);
        }
        return mn <= mx;
    };

    while (l < r) {
        int mid = l + r >> 1;
        if (chk(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}