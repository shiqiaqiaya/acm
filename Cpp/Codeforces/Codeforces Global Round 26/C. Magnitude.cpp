#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 1);

    vector<array<int, 2>> c = {{0, 0}, {0, 1}};

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        auto tmp = minmax({c[0][0] + a[i], c[1][0] + a[i], abs(c[0][0] + a[i]), abs(c[1][0] + a[i])});
        vector<array<int, 2>> nc = {{tmp.first, 0}, {tmp.second, 0}};
        // cerr << i << " " << c[0][1] << " " << tmp.second << "\n";
        if (tmp == pair{tmp.first, tmp.first}) {
            if (c[0][0] + a[i] == tmp.second) {
                (nc[1][1] += c[0][1]) %= mod;
            }
            if (c[1][0] + a[i] == tmp.second) {
                (nc[1][1] += c[1][1]) %= mod;
            }
            if (abs(c[0][0] + a[i]) == tmp.second) {
                (nc[1][1] += c[0][1]) %= mod;
            }
            if (abs(c[1][0] + a[i]) == tmp.second) {
                (nc[1][1] += c[1][1]) %= mod;
            }
        } else {
            if (c[0][0] + a[i] == tmp.first) {
                (nc[0][1] += c[0][1]) %= mod;
            }
            if (c[0][0] + a[i] == tmp.second) {
                (nc[1][1] += c[0][1]) %+ mod;
            }
            if (c[1][0] + a[i] == tmp.first) {
                (nc[0][1] += c[1][1]) %= mod;
            }
            if (c[1][0] + a[i] == tmp.second) {
                (nc[1][1] += c[1][1]) %= mod;
            }
            if (abs(c[0][0] + a[i]) == tmp.first) {
                (nc[0][1] += c[0][1]) %= mod;
            }
            if (abs(c[0][0] + a[i]) == tmp.second) {
                (nc[1][1] += c[0][1]) %+ mod;
            }
            if (abs(c[1][0] + a[i]) == tmp.first) {
                (nc[0][1] += c[1][1]) %= mod;
            }
            if (abs(c[1][0] + a[i]) == tmp.second) {
                (nc[1][1] += c[1][1]) %= mod;
            }
        }

        swap(nc, c);
    }

    cout << c[1][1] << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}