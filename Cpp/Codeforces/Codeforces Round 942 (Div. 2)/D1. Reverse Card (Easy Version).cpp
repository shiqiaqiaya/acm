#include <bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, m, ans = 0;
    cin >> n >> m;

    for (int b = 1; b <= m; b++) {
        for (int a = b; a <= n; a += b) {
            if ((a + b) % (b * __gcd(a, b)) == 0) {
                ans++;
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