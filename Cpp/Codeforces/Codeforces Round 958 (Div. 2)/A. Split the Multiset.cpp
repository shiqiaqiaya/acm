#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << "0\n";
        return;
    }

    if (n > k) {
        cout << (n - 1) / (k - 1) + (!!((n - 1) % (k - 1))) << "\n";
        return;
    }

    cout << "1\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}