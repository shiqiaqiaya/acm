#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int x, y;
    cin >> x >> y;

    for (int i = 0; ; i++) {
        if ((x ^ y) >> i & 1) {
            cout << (1ll << i) << "\n";
            return;
        }
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}