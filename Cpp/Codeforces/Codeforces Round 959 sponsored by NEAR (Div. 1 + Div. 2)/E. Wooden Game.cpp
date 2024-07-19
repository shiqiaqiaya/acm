#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        for (int j = 1; j < a[i]; j++) {
            int x;
            cin >> x;
        }
    }

    int ans = 0;

    for (int bit = 21; ~bit; bit--) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (a[j] >> bit & 1) {
                cnt++;
            }
        }
        if (cnt >= 2) {
            cout << (ans | ((1ll << bit + 1) - 1)) << "\n";
            return;
        } else if (cnt == 1) {
            for (int j = 1; j <= n; j++) {
                if (a[j] >> bit & 1) {
                    a[j] ^= 1ll << bit;
                }
            }
            ans |= 1ll << bit;
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