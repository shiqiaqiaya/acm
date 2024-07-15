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

vector<int> fact, invfact;
auto init = [](int n) {
    fact = invfact = vector<int>(n + 1);
    fact[0] = invfact[0] = 1;	//0的阶乘为1
    for (int i = 1; i <= n; i++) {
        (fact[i] = fact[i - 1] * i) %= mod;
        (invfact[i] = invfact[i - 1] * binpow(i, mod - 2)) %= mod;
    }
};

auto Combine = [](int n, int m) {
    return m > n || n < 0 || m < 0 ? (int)0 : (((fact[n] * invfact[m]) % mod) * invfact[n - m]) % mod;
};

auto Permutation = [](int n, int m) {
    return m > n || n < 0 || m < 0 ? (int)0 : (fact[n] * invfact[n - m]) % mod;
};

void QAQ() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    array<int, 2> sum = {accumulate(a.begin() + 1, a.begin() + k + 1, 0ll) % mod, accumulate(a.begin() + k + 1, a.end(), 0ll) % mod}, m = {n - k + 2 >> 1, (n - k + 1) - (n - k + 2 >> 1)};

    if (n == k) {
        cout << (sum[0] + sum[1]) % mod << " " << 0 << "\n";
        return;
    }

    array<int, 2> res = {0, 0};

    for (int i = 0; i <= k; i++) {
        int tmp = Combine(m[0] + i - 1, i) * Combine(m[1] + (k - i) - 1, k - i) % mod;
        (res[0] += tmp * i) %= mod, (res[1] += tmp * (k - i)) %= mod;
    }

    (res[0] *= binpow(Combine(n, k), mod - 2)) %= mod, (res[1] *= binpow(Combine(n, k), mod - 2)) %= mod;
    (res[0] *= binpow(k, mod - 2)) %= mod, (res[1] *= binpow(k, mod - 2)) %= mod;

    cout << (sum[0] * res[0] % mod + sum[1] * (n - k + 1 >> 1) % mod * binpow(n - k, mod - 2) % mod) % mod << " " << (sum[0] * res[1] % mod + sum[1] * (n - k - (n - k + 1 >> 1)) % mod * binpow(n - k, mod - 2) % mod) % mod << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    init(1e6);

    while (t--) {
        QAQ();
    }
}