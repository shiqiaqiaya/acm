#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n;
    cin >> n;

    while (n) {
        int t = n % 10;

        if (0 <= t && t <= 8 && (n >= t + 10)) {
            n -= (t + 10);
            n /= 10;
        } else {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}