#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 1);

    int res = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > 4) {
            a[i] = 0;
            res++;
        }
    }

    vector dp(n + 1, array<int, 4>{(int)4e18, (int)4e18, (int)4e18, (int)4e18});

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] <= 0) {
            dp[i][0] = min({dp[i][0], dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]});
            dp[i][1] = min({dp[i][1], dp[i - 1][0] + 1, dp[i - 1][1] + 1, dp[i - 1][2] + 1, dp[i - 1][3] + 1});
            dp[i][2] = min({dp[i][2], dp[i - 1][0] + 1, dp[i - 1][1] + 1, dp[i - 1][2] + 1, dp[i - 1][3] + 1});
        } if (0 < a[i] && a[i] <= 2) {
            dp[i][0] = min({dp[i][0], dp[i - 1][0] + 1, dp[i - 1][1], dp[i - 1][2] + 1, dp[i - 1][3]});
            dp[i][1] = min({dp[i][1], dp[i - 1][0] + 1, dp[i - 1][1] + 1, dp[i - 1][2] + 1, dp[i - 1][3] + 1});
            dp[i][2] = min({dp[i][2], dp[i - 1][1] + 1, dp[i - 1][3] + 1});
        } if (2 < a[i] && a[i] <= 4) {
            dp[i][0] = min({dp[i][0], dp[i - 1][0] + 1, dp[i - 1][1] + 1, dp[i - 1][2] + 1, dp[i - 1][3]});
            dp[i][1] = min({dp[i][1], dp[i - 1][2] + 1, dp[i - 1][3] + 1});
            dp[i][2] = min({dp[i][2], dp[i - 1][1] + 1, dp[i - 1][3] + 1});
        }
        dp[i][3] = min({dp[i][3], dp[i - 1][0] + 2, dp[i - 1][1] + 2, dp[i - 1][2] + 2, dp[i - 1][3] + 2});
    }

    cout << *min_element(dp[n].begin(), dp[n].end()) + res << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}