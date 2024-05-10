#include <bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<array<int, 2>> ans;

    for (int i = 1; i <= n; i++) {
        if (a[i] != i) {
            int pos = i;
            for (int j = i + 1; j <= n; j++) {
                if (a[j] < a[i]) {
                    pos = j;
                }
            }
            ans.push_back({i, pos});
            sort(a.begin() + i, a.begin() + pos + 1);
        }
    }

    cout << ans.size() << "\n";
    
    for (auto & [l, r] : ans) {
        cout << l << " " << r << "\n";
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    QWQ();

    while (t--) {
        QAQ();
    }
}