#include <bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (count_if(a.begin() + 1, a.end(), [&](const auto & x) { return a[x] == &x - &a[0]; })) {
        cout << 2 << "\n";
    } else {
        cout << 3 << "\n";
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