#include<bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 1), sum(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    vector g(n + 1, vector<int>(2 * n + 1)), ans(n + 1, vector<int>(2 * n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            g[i][j] = max(sum[i] - sum[max(0ll, i - j - 1)], sum[min(n, i + j)] - sum[i - 1]);
        }
    }

    vector<int> left(n + 1), right(n + 1);

    for (int j = 1; j <= 2 * n; j++) {
        vector<int> leftn(n + 1), rightn(n + 1);
        for (int i = 1; i <= n; i++) {
            if (1 <= i - 1) {
                leftn[i] = max(left[i - 1], g[i][j]);
            } else {
                leftn[i] = g[i][j];
            }
            if (i + 1 <= n) {
                rightn[i] = max(right[i + 1], g[i][j]);
            } else {
                rightn[i] = g[i][j];
            }
            ans[i][j] = max(leftn[i], rightn[i]);
        }
        swap(left, leftn), swap(right, rightn);
    }

    int res = 0;

    for (int i = 1; i <= n; i++) {
        int tmp = 0;
        for (int j = 1; j <= 2 * n; j++) {
            tmp ^= j * ans[i][j];
        }
        res ^= (i + tmp);
    }
    cout << res << "\n";
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