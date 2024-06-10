#include<bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n;
    cin >> n;

    vector<array<int, 2>> a(n + 1);

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i][0];
        a[i][1] = i;
    }

    sort(a.begin() + 1, a.end());

    int now = 0, lst = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i][1] > now) {
            ans += (a[i][1] - now + lst) / a[i][0];
            lst = (a[i][1] - now + lst) % a[i][0];
            now = a[i][1];
        }
    }

    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;

    while (t--) {
        QAQ();
    }
}