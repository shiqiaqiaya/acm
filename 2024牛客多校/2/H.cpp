#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, x, y;
    cin >> n >> x >> y;

    int ans = 0;

    map<int, map<int, int>> mp;

    string s;
    cin >> s;

    if (x == 0 && y == 0) {
        cout << n * (n + 1) / 2 << "\n";
        return;
    }

    s = " " + s;

    array<int, 2> t = {0, 0};

    mp[0][0]++;

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'A') {
            t[0]--;
        } else if (s[i] == 'D') {
            t[0]++;
        } else if (s[i] == 'W') {
            t[1]++;
        } else {
            t[1]--;
        }
        mp[t[0]][t[1]]++;
        if (mp[t[0] - x].count(t[1] - y)) {
            ans += mp[t[0] - x][t[1] - y] * (n - i + 1);
            mp[t[0] - x].erase(t[1] - y);
        }
    }

    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        QAQ();
    }
}