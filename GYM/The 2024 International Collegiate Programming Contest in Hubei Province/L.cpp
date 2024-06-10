#include <bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << "\n";
        return;
    }

    auto tmp = [&](int a) {
        for (int i = 2; i * i <= a; i++) {
            if (a % i == 0) {
                return i;
            }
        }
        return a;
    };

    auto F = [&](int a, int b) {
        int ans = min({lcm(a, b), lcm(a, 2) + lcm(2, b)});
        if (__gcd(a, b) != 1) {
            ans = min(ans, a + b);
        } else {
            for (int i = 2; i * i <= a; i++) {
                if (a % i == 0) {
                    ans = min({ans, a + i * b, a + lcm(i, 2) + lcm(2, b)});
                    break;
                }
            }
            ans = min({ans, a + a * b, a + lcm(a, 2) + lcm(2, b)});
        }
        return ans;
    };

    cout << min({F(a, b), F(b, a), a + b + lcm(tmp(a), tmp(b)), a + b + lcm(2, tmp(a)) + lcm(2, tmp(b))}) << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    QWQ();

    while (t--) {
        QAQ();
    }
}