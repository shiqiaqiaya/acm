#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, m, mod;
    cin >> n >> m >> mod;

    vector C(max(n, m) + 1, vector<int>(max(n, m) + 1)), f(max(n, m) + 1, vector<int>(max(n, m) + 1));
    vector<int> pw(max(n, m) + 1), fac(max(n, m) + 1);

   for (int i = 0; i <= max(n, m); i++) {
       for (int j = 0; j <= i; j++) {
           if (!j) {
                C[i][j] = 1;
           } else {
                (C[i][j] = C[i - 1][j] + C[i - 1][j - 1]) %= mod;
           }
       }
       if (i == 0) {
            pw[i] = fac[i] = 1;
       } else {
            (pw[i] = pw[i - 1] * 2) %= mod;
            (fac[i] = fac[i - 1] * i) %= mod;
       }
   }

    f[0][0] = 1;
   for (int i = 1; i <= max(n, m); i++) {
        for (int j = 1; j <= max(n, m); j++) {
            (f[i][j] = (f[i - 1][j - 1] + j * f[i - 1][j])) %= mod;
        }
   }

    int ans = 0;

   for (int i = 2; i <= n; i++) {
        int sum = 1, tmp = C[n][i], del = 0, cnt = 1;
        for (int j = 1; j <= m - 1; j++) {
            (sum *= pw[i] - 1) %= mod;
            (tmp *= pw[n - i]) %= mod;
        }
        for (int j = m - 1; j >= i; j--) {
            (del += C[m - 1][j] * f[j][i] % mod * fac[i] % mod * cnt) %= mod;
            (cnt *= pw[i] - i - 1) %= mod;
        }
        (ans += tmp * (sum - del)) %= mod;
   }

   cout << (ans + mod) % mod << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;

    while (t--) {
        QAQ();
    }
}