#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n + 1);

    set<int> now = {1};
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (x % a[i]) continue;
        vector<int> tmp;
        for (auto & t : now) {
            if (t * a[i] < x) {
                tmp.push_back(t * a[i]);
            } else if (t * a[i] == x) {
                now = {a[i], 1};
                ans++;
                tmp = vector<int>();
                break;
            }
        }
        for (auto & x : tmp) {
            now.insert(x);
        }
    }

    cout << ans + 1 << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}