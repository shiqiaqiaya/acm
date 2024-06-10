#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, lm = 1;
    cin >> n;

    vector<int> a(n + 1);
    unordered_map<int, int> mp;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        lm = lcm(lm, a[i]);
        mp[a[i]]++;
    }

    int sum = 0;

    for (auto & [x, cnt] : mp) {
        sum += lm / x * cnt;
    }

    if (sum >= lm) {
        cout << "-1\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        cout << lm / a[i] << " \n"[i == n];
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