#include<bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n, sum = 0;
    cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int ans = 0;

    for (int bit = 33; ~bit; bit--) {
        if (n * ((1ll << bit) - 1) >= sum) {

        } else {
            ans |= 1ll << bit;
            int t = sum / (1ll << bit);
            sum -= min(n, t) * (1ll << bit);
        }
    }

    cout << ans << "\n";
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