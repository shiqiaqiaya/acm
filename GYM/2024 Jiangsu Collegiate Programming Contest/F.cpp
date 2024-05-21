#include<bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    double sum = accumulate(a.begin() + 1, a.begin() + k, 0ll);

    cout << fixed << setprecision(12);

    for (int i = k; i <= n; i++) {
        sum += a[i];
        sum -= a[i - k];

        if (sum >= 1024 * k) {
            cout << sum / (k * 1024) << " MiBps\n";
        } else {
            cout << sum / k << " KiBps\n";
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