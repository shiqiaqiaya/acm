#include <bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n;
    cin >> n;

    vector<pair<string, int>> mp(n);

    for (int i = 0; i < n; i++) {
        cin >> mp[i].first >> mp[i].second;
    }

    sort(mp.begin(), mp.end());

    int sum = accumulate(mp.begin(), mp.end(), 0ll, [&](auto now, auto & x) { return now + x.second; });

    cout << mp[sum % n].first << "\n";
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