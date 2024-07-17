#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

void QAQ() {
    int n;
    cin >> n;

    vector<int> t;

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        while (u--) {
            (ans -= t.back() * t.size()) %= mod;
            (ans += mod) %= mod;
            t.pop_back();
        }
        t.push_back(v);
        (ans += v * t.size()) %= mod;
        (ans += mod) %= mod;
        cout << ans << "\n";
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;

    while (t--) {
        QAQ();
    }
}