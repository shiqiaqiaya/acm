#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;

void QWQ() {

}

void QAQ() {
    auto binpow = [&](int a, int b, int res = 1) {
        for (a %= mod; b; b >>= 1) {
            if (b & 1) {
                (res *= a) %= mod;
            }
            (a *= a) %= mod;
        }
        return res;
    };

    int n, ans = 0, tmp = 1;
    cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        (ans += a[i] * tmp) %= mod;
        (tmp *= (n - i) * binpow(i, mod - 2) % mod) %= mod;
        cout << tmp << " / \n";
    }

    cout << ans * binpow(binpow(2, n), mod - 2) % mod << "\n";
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