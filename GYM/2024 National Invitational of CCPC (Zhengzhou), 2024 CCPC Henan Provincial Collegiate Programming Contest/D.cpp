#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

void QWQ() {

}

void QAQ() {
    int n;
    cin >> n;

    vector<array<int, 2>> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1];
    }

    sort(a.begin() + 1, a.end(), [&](auto & x, auto & y) {
        return x[0] + x[1] < y[0] + y[1];
    });

    double ans = 0;

    for (int i = 1; i < n; i++) {
        ans = max(ans, (double)(abs(a[i][0] - a[i + 1][0]) + abs(a[i][1] - a[i + 1][1])) / hypot(a[i][0] - a[i + 1][0], a[i][1] - a[i + 1][1]));
    }

    sort(a.begin() + 1, a.end(), [&](auto & x, auto & y) {
        return x[0] - x[1] < y[0] - y[1];
    });

    for (int i = 1; i < n; i++) {
        ans = max(ans, (double)(abs(a[i][0] - a[i + 1][0]) + abs(a[i][1] - a[i + 1][1])) / hypot(a[i][0] - a[i + 1][0], a[i][1] - a[i + 1][1]));
    }

    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cout << fixed << setprecision(12);
    int t = 1;
    cin >> t;

    QWQ();

    while (t--) {
        QAQ();
    }
}