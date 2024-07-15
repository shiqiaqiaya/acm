#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n + 1);
    iota(a.begin(), a.end(), 0);
    sort(a.begin() + 1, a.end(), greater<>());

    for (int i = 1; i <= n; i++) {
        if (a[i] == m) {
            sort(a.begin() + i, a.end());
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}