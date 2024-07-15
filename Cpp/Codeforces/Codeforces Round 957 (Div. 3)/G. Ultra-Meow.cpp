#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

auto binpow = [](int a, int b, int res = 1) {
    for (a %= mod; b; b >>= 1) {
        if (b & 1) {
            (res *= a) %= mod;
        }
        (a *= a) %= mod;
    }
    return res;
};

auto inv = [](int x, int mod) {
    return binpow(x, mod - 2);
};

vector<int> fact, invfact;
auto init = [](int n) {
    fact = invfact = vector<int>(n + 1);
    fact[0] = invfact[0] = 1;	//0的阶乘为1
    for (int i = 1; i <= n; i++) {
        (fact[i] = fact[i - 1] * i) %= mod;
        (invfact[i] = invfact[i - 1] * inv(i, mod)) %= mod;
    }
};

auto Combine = [](int n, int m) {
    return m > n || n < 0 || m < 0 ? (int)0 : (((fact[n] * invfact[m]) % mod) * invfact[n - m]) % mod;
};

auto Permutation = [](int n, int m) {
    return m > n || n < 0 || m < 0 ? (int)0 : (fact[n] * invfact[n - m]) % mod;
};

void QAQ() {
    int n;
    cin >> n;

    int ans = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= 2 * n + 1; j++) {
            (ans += j * Combine(min(n, j - 1), j - 1 - i) % mod * Combine(max(0ll, n - j), 2 * i - j + 1)) %= mod;
        }
    }

    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    init(1e4);

    while (t--) {
        QAQ();
    }
}