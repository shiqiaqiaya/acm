#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int mod = 998244353;

auto binpow = [](ll a, ll k) {
    ll ans = 1;
    for (; k; k >>= 1) {
    if (k & 1) {
        ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
    }
    return ans;
};

void QWQ() {

}

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(2 * n + 1);

    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
    }

    multiset<int> s(a.begin() + 1, a.end());

    s.erase(-1);

    map<int, int> mp;
    int cnt = 0, ans = 1;

    for (int i = 1; i <= 2 * n; i++) {
        if (a[i] != -1) {
            mp[a[i]]++;
            cnt++;
        } else {
            if (mp.begin() -> first == *s.begin()) {
                s.erase(s.begin());
                (ans *= (mp.begin() -> second) * binpow(cnt, mod - 2) % mod) %= mod;
                mp.begin() -> second--;
                cnt--;
                if (mp.begin() -> second == 0) {
                    mp.erase(mp.begin());
                }
            } else {
                cout << 0 << "\n";
                return;
            }
        }
    }

    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;

    while (t--) {
        QAQ();
    }
}