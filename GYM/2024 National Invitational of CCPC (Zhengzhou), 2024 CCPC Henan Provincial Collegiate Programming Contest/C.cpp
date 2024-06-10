#include<bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 1), lst(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        lst[a[i]] = i;
    }

    for (int i = 1; i <= n; ) {
        set<int> s;
        int l = i, r = lst[a[i]];
        for ( ; i <= r; i++) {
            r = max(r, lst[a[i]]);
        }
        sort(a.begin() + l, a.begin() + i, greater<>());
    }

    vector<int> lis;

    for (int i = 1; i <= n; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
        if (it == lis.size()) {
            lis.push_back(a[i]);
        } else {
            lis[it] = a[i];
        }
    }

    cout << n - count(lst.begin() + 1, lst.end(), 0) - lis.size() << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;

    while (t--) {
        QAQ();
    }
}