#include <bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n;
    cin >> n;

    vector<int> p(n + 1);

    int fl = -1;

    int ans = 0, mn = 1e9, mx = 0;

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    if (is_sorted(p.begin() + 1, p.end())) {
        cout << 2 * n * (2 * n + 1) / 2 << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (p[i] != i) {
            if (fl == -1) {
                fl = p[i] + i;
            } else if (fl != p[i] + i) {
                fl = 0;
            }
            mn = min(mn, p[i]), mx = max(mx, p[i]);
        }
    }

    if (fl > 0) {
        ans++;
    }

    for (int l = 1; l <= mn + n; l++) {
        ans += 2 * n - max(mx + 1, l + 1) + 1;
    }

    cout << ans << "\n";
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