#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

void QAQ() {
    int n, k;
    cin >> n >> k;

    vector S(n + 1, vector<int>(k + 1));
    S[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            (S[i][j] = S[i - 1][j - 1] + j * S[i - 1][j]) %= mod;
        }
    }

    cout << S[n][k] << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;

    while (t--) {
        QAQ();
    }
}