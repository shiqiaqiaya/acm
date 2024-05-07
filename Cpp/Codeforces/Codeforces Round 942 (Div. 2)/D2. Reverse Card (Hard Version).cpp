#include <bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, m, ans = 0;
    cin >> n >> m;

    for (int a = 1; a * a <= n; a++) {
        for (int b = 1; b * b <= m; b++) {
            if (__gcd(a, b) == 1) {
                ans += min(n / a, m / b) / (a + b);
            }
        }
    }

    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}