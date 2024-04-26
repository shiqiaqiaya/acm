#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

vector<int> is_prime, prime, f;

auto Eratosthenes = [](int n) {
    is_prime = vector<int>(n + 1, true), prime = vector<int>(), f = vector<int>(n + 1);
    is_prime[1] = is_prime[0] = false;  //true为素数
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime.push_back(i);
            for (int j = i; j <= n; j += i) {
                (f[j] += (i - 1) * (j / i) % i) %= mod;
                if (j + i <= n) {
                    ((f[j + i] -= (i - 1) * (j / i) % i) += mod) %= mod;
                }
            }
            for (int j = i * i; j <= n; j += i) {   //从i * i开始, 因为从2到i-1的倍数之前都筛过
                is_prime[j] = false;
            }
        }
    }
    int i = 4;
    for (int j = i; j <= n; j += i) {
        (f[j] += 2 * (j / i) % i) %= mod;
        if (j + i <= n) {
            ((f[j + i] -= 2 * (j / i) % i) += mod) %= mod;
        }
    }
    for (int i = 1; i <= n; i++) {
        (f[i] += f[i - 1]) %= mod;
    }
    for (int i = 1; i <= n; i++) {
        (f[i] += f[i - 1]) %= mod;
    }
};

void QAQ() {
    int n;
    cin >> n;

    cout << f[n] << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    Eratosthenes(1e6);

    while (t--) {
        QAQ();
    }
}