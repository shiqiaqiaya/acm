#include <bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b + c & 1) {
        cout << "-1\n";
        return;
    }

    int ans = 0;
    ans += a;

    while (a--) {
        if (b > c) {
            b--;
        } else {
            c--;
        }
    }

    cout << ans + min(b, c) << "\n";
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