#include <bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 1);

    vector sum(n + 1, vector<int>(22));

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 0; j < 22; j++) {
            sum[i][j] = sum[i - 1][j] + (a[i] >> j & 1);
        }
    }

    int l = 1, r = n;

    auto chk = [&](int mid) {
        for (int j = 0; j < 22; j++) {
            int t = sum[mid][j] > 0;
            for (int i = 1; i + mid - 1 <= n; i++) {
                if ((sum[i + mid - 1][j] - sum[i - 1][j] > 0) == t) {

                } else {
                    return 0;
                }
            }
        }

        return 1;
    };

    while (l < r) {
        int mid = l + r >> 1;
        if (chk(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << "\n";
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