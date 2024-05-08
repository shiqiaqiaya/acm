#include<bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n, k;
    cin >> n >> k;

    k = n * n - k + 1;

    auto query = [&](int i, int j, int x) {
        cout << "? " << i << " " << j << " " << x << endl;
        cin >> x;
        return x;
    };

    int l = 1, r = n * n;

    auto chk = [&](int mid) {
        int res = 0;
        int x = n, y = 1;
        while (1 <= x && y <= n) {
            if (query(x, y, mid)) {
                res += x;
                y++;
            } else {
                x--;
            }
        }
        return res >= k;
    };

    while (l < r) {
        int mid = l + r >> 1;

        if (chk(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << "! " << l << endl;
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