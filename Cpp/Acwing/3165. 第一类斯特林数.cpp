#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

void QAQ() {
    int n, k;
    cin >> n >> k;

    vector s(n + 1, vector<int>(k + 1));
    s[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            (s[i][j] = s[i - 1][j - 1] + (i - 1) * s[i - 1][j]) %= mod;
        }
    }

    cout << s[n][k] << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;

    while (t--) {
        QAQ();
    }
}