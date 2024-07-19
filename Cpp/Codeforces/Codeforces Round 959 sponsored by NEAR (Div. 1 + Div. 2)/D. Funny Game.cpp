#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 1), vis(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<array<int, 2>> ans;
    for (int x = n - 1; x; x--) {
        map<int, vector<int>> mp;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            mp[a[i] % x].push_back(i);
            if (mp[a[i] % x].size() >= 2) {
                vis[i] = 1;
                ans.push_back({mp[a[i] % x].front(), i});
                break;
            }
        }
    }

    cout << "YES\n";

    reverse(ans.begin(), ans.end());

    for (auto [u, v] : ans) {
        cout << u << " " << v << "\n";
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