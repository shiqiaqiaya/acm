#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int a, b, c;
    cin >> a >> b >> c;

    int ans = a * b * c;

    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j + i <= 5; j++) {
            for (int k = 0; k + j + i <= 5; k++) {
                ans = max(ans, (a + i) * (b + j) * (c + k));
            }
        }
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