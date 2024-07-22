#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 1);

    map<int, int> mp;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        if (it -> second & 1) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}