#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    s = " " + s;

    vector<string> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        reverse(a[i].begin(), a[i].end());
        a[i] = " " + a[i];
    }

    vector dp(k + 1, vector<array<int, 2>>(n + 1));

    dp[0][0] = {-1, -1};

    for (int i = 1; i <= k; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            cnt += a[j][i] == '1';
        }
        for (int j = 0; j <= n; j++) {
            if (dp[i - 1][j] == array<int, 2>()) continue;
            if (((j + cnt) & 1) == s[i] - '0') {
                dp[i][j + cnt >> 1] = {j + 1, 0};
            } if (((j + n - cnt) & 1) == s[i] - '0') {
                dp[i][j + n - cnt >> 1] = {j + 1, 1};
            }
        }
    }

    if (dp[k][0] == array<int, 2>{0, 0}) {
        cout << "-1\n";
        return;
    }

    string ans;

    for (int i = k, pos = 0; i; i--) {
        ans += dp[i][pos][1] + '0';
        pos = dp[i][pos][0] - 1;
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