#include <bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int sum = 0;
    int h;
    cin >> h;

    for (int i = 0; ; i++) {
        sum += 1ll << i;
        if (sum > h) {
            cout << i + 1 << "\n";
            return;
        }
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;

    QWQ();

    while (t--) {
        QAQ();
    }
}