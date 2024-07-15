#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            a[j] = lcm(a[j], i);
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