#include <bits/stdc++.h>
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
        a[i] -= i;
    }

    int sum1 = 0, sum2 = 0;
    multiset<int> top;
    multiset<int, greater<int>> but;

    int ans = 1, l = 1;

    for (int i = 1; i <= n; i++) {
        if (!but.size() || a[i] <= *but.begin()) {
            but.insert(a[i]);
            sum2 += a[i];
        } else {
            top.insert(a[i]);
            sum1 += a[i];
        }

        while (top.size() < but.size()) {
            sum1 += *but.begin();
            sum2 -= *but.begin();
            top.insert(*but.begin());
            but.erase(but.begin());
        }

        while (top.size() > but.size()) {
            sum1 -= *top.begin();
            sum2 += *top.begin();
            but.insert(*top.begin());
            top.erase(top.begin());
        }

        if (top.size() && but.size()) {
            int res = sum1 - sum2 + (*but.begin()) * (but.size() - top.size());
            while (top.size() && but.size() && res > k) {
                if (but.contains(a[l])) {
                    but.extract(a[l]);
                    sum2 -= a[l];
                } else {
                    sum1 -= a[l];
                    top.extract(a[l]);
                }
                l++;

                while (top.size() < but.size()) {
                    sum1 += *but.begin();
                    sum2 -= *but.begin();
                    top.insert(*but.begin());
                    but.erase(but.begin());
                }

                while (top.size() > but.size()) {
                    sum1 -= *top.begin();
                    sum2 += *top.begin();
                    but.insert(*top.begin());
                    top.erase(top.begin());
                }

                res = sum1 - sum2 + (*but.begin()) * (but.size() - top.size());
            }
            ans = max(ans, (int)top.size() + (int)but.size());
        }
    }

    cout << ans << "\n";
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