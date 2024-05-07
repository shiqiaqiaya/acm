#include <bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a.begin() + 1, a.end());

    int now = 0, mx = 0;
    a[0] = a[1];

    for (int i = 1; i <= n; i++) {
        if (now + (a[i] - a[i - 1]) * (i - 1) > k) {
            int t = (k - now) / (i - 1);
            mx = (t + a[i - 1]);
            int ans = n * mx - (n - 1), tmp = 0;
            for (int j = i; j <= n; j++) {
                if (a[j] > mx) {
                    tmp++;
                }
            }
            tmp += k - now - (i - 1) * t;
            cout << ans + tmp << "\n";
            return;
        }
        now += (a[i] - a[i - 1]) * (i - 1);
    }

    int t = (k - now) / n;

    cout << n * (t + a[n]) - (n - 1) + (k - now - n * t) << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}