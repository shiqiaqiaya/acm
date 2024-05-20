#include <bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    auto query = [&](int l, int x) {
        cout << "? " << l << " " << x << endl;
        cin >> x;
        return x;
    };

    int n, k;
    cin >> n >> k;

    int mx = n;

    while (1) {
        if (query(1, mx * n) == n) {
            break;
        }
        mx--;
    }

    if (k == 1) {
        cout << "! " << mx * n << endl;
        return;
    }

    for (int len = n / k; len; len--) {
        if ([&]() {
            vector<array<int, 2>> t;

            int pos = 1;

            while (t.size() < k && pos <= n) {
                int tmp = query(pos, mx * len);
                if (tmp == n + 1) {
                    return false;
                }
                t.push_back({pos, tmp});
                pos = tmp + 1;
            }

            return t.size() == k && pos == n + 1;
        } ()) {
            cout << "! " << mx * len << endl; 
            return;
        }
    }

    cout << "! " << -1 << endl;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    QWQ();

    while (t--) {
        int tt;
        QAQ();
        cin >> tt;
    }
}