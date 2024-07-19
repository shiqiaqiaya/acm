#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int x, y;
    double ans = 0;
    cin >> x >> y;

    while (cin >> x >> y) {
        int tx, ty;
        cin >> tx >> ty;
        ans += hypotl(tx - x, ty - y);
    }

    ans /= 10000;

    array<int, 2> res = {(int)ans, (ans - (int)ans) * 60 + 0.5};

    if (res[1] == 60) {
        res[0]++, res[1] -= 60;
    }

    cout << res[0] << ":" << setw(2) << setfill('0') << res[1] << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;

    while (t--) {
        QAQ();
    }
}