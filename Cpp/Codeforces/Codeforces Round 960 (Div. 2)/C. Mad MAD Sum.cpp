#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 1), ta(1);
    map<int, int> ttmp, mp;

    int ans = 0, now = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ttmp[a[i]]++;
        if (ttmp[a[i]] >= 2) {
            now = max(now, a[i]);
        }
        ta.push_back(now);
        mp[now]++;
    }

    ans = accumulate(a.begin() + 1, a.end(), 0ll);
    int sum = 0;
    now = 0;
    for (int i = 1; i <= n; i++) {
        ans += sum + ta[i];
        if (mp[ta[i]] >= 2) {
            sum += ta[i];
            now = ta[i];
        } else {
            sum += now;
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