#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n;
    cin >> n;

    vector<int> tmp;

    for (int i = 63; ~i; i--) {
        if (n >> i & 1) {
            tmp.push_back(i);
        }
    }

    int now = 0, xx = n;

    vector<int> ans;

    for (int i = 0; i < tmp.size(); i++) {
        xx ^= 1ll << tmp[i];
        ans.push_back(now | xx);
        now ^= 1ll << tmp[i];
    }

    if (ans[0] == 0) {
        ans = vector<int>(ans.begin() + 1, ans.end());
    }

    ans.push_back(n);

    cout << ans.size() << "\n";

    for (auto & x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}