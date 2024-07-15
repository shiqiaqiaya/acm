#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n;
    cin >> n;

    string t = to_string(n);

    vector<array<int, 2>> ans;

    for (int a = 1; a <= 10000; a++) {
        for (int b = max(1ll, a * (int)t.size() - 10); b <= min(a * (int)t.size(), 10000ll); b++) {
            string tmp;
            for (int k = a * t.size() - b, j = 0; k; k--, (j += 1) %= t.size()) {
                tmp += t[j];
            }
            if (tmp.size()) {
                int tt = stoll(tmp);
                if (tt == a * n - b) {
                    ans.push_back({a, b});
                }
            }
        }
    }

    cout << ans.size() << "\n";

    for (auto & [x, y] : ans) {
        cout << x << " " << y << "\n";
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