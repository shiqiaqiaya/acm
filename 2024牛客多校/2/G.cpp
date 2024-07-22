#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

vector<int> prime;

auto init = [](int n) {
    for (int i = 2; i <= n; i++) {
        int ok = 0;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                ok = 1;
                break;
            }
        }
        if (!ok) {
            prime.push_back(i);
        }
    }
};

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> dp(1ll << 11), mp(1ll << 11, 1);
    vector<int> tmp(prime.begin(), prime.begin() + 11);
    dp[0] = 1;

    for (int state = 1; state < dp.size(); state++) {
        for (int bit = 10; ~bit; bit--) {
            if (state >> bit & 1) {
                (mp[state] = mp[state ^ (1ll << bit)] * tmp[bit]) %= mod;
                break;
            }
        }
    }
    for (int now = 10; now < prime.size(); now++) {
        tmp.pop_back(), tmp.push_back(prime[now]);
        for (int state = 1ll << 10; state < mp.size(); state++) {
            (mp[state] = mp[state ^ (1ll << 10)] * tmp.back()) %= mod;
            dp[state] = 0;
        }

        auto ta = a;

        for (int i = 1; i < ta.size(); i++) {
            if (now != 10 && a[i] % tmp.back()) continue;
            int sum = 1, mask = 0;
            for (auto & x : tmp) {
                int tt = 0;
                while (ta[i] % x == 0) {
                    ta[i] /= x;
                    tt++;
                }
                if (tt & 1) {
                    mask |= 1ll << (int)(&x - &tmp[0]);
                }
                tt >>= 1;
                while (tt--) {
                    sum *= x;
                }
            }
            if (ta[i] != 1) continue;
            auto dpn = dp;
            for (int state = 0; state < dp.size(); state++) {
                int nmask = state ^ mask;
                int tmask = state & mask;
                (dpn[nmask] += dp[state] * mp[tmask] % mod * sum % mod) %= mod;
            }
            swap(dp, dpn);
        }
    }


    cout << (dp[0] - 1 + mod) % mod << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;

    init(1e3);

    while (t--) {
        QAQ();
    }
}