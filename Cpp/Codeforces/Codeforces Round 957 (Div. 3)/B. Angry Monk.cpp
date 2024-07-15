#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, k;
    cin >> n >> k;

    vector<int> a(k + 1);

    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }

    sort(a.begin() + 1, a.end());

    int ans = 0;

    for (int i = 1; i < k; i++) {
        ans += a[i] * 2 - 1;
    }

    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}