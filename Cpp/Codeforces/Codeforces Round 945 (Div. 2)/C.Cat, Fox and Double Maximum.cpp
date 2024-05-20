#include <bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 1);

    int ok = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            ok = i;
        }
    }

    vector<int> ans(n + 1);

    if (ok & 1) {
        set<array<int, 2>> s1;

        for (int i = 2; i <= n; i += 2) {
            s1.insert({a[i], i});
        }

        int now = n;

        for (auto & [x, id] : s1) {
            ans[id] = now--;
        }

        set<array<int, 2>, greater<>> s2;

        for (int i = 1; i <= n; i += 2) {
            s2.insert({a[i], i});
        }

        now = 1;

        for (auto & [x, id] : s2) {
            ans[id] = now++;
        }
    } else {
        set<array<int, 2>> s1;

        for (int i = 1; i <= n; i += 2) {
            s1.insert({a[i], i});
        }

        int now = n;

        for (auto & [x, id] : s1) {
            ans[id] = now--;
        }

        set<array<int, 2>, greater<>> s2;

        for (int i = 2; i <= n; i += 2) {
            s2.insert({a[i], i});
        }

        now = 1;

        for (auto & [x, id] : s2) {
            ans[id] = now++;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
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