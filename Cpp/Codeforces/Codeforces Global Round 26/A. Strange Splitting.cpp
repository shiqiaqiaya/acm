#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (!count_if(a.begin() + 1, a.end(), [&](auto & x) { return x != a[1]; })) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    int mn = *min_element(a.begin() + 1, a.end()), mx = *max_element(a.begin() + 1, a.end());

    int ok = 1;

    int cnt1 = count_if(a.begin() + 1, a.end(), [&](auto & x) {return x == mn; });

    for (int i = 1; i <= n; i++) {
        if (ok && ((a[i] == mn && cnt1 > 1) || (a[i] == mx && cnt1 == 1))) {
            ok = 0;
            cout << "R";
        } else {
            cout << "B";
        }
    }

    cout << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}