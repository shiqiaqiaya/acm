#include<bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int mx = *max_element(a.begin() + 1, a.end());

    if (count_if(a.begin() + 1, a.end(), [&](auto & x) { return x == mx; }) & 1) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;

    QWQ();

    while (t--) {
        QAQ();
    }
}