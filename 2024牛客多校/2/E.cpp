#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int x;
    cin >> x;

    for (int bit = 0; ; bit++) {
        if (x >> bit & 1) {
            int y = x - (1ll << bit);
            if (y) {
                cout << y << "\n";
            } else {
                cout << "-1\n";
            }
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