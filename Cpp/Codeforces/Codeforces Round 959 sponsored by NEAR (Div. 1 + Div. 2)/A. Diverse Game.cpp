#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, m;
    cin >> n >> m;
    vector a(n + 1, vector<int>(m + 1));
    vector<int> t;
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            t.push_back(a[i][j]);
        }
    }
    t.push_back(t.front());
    if (n == 1 && m == 1) {
        cout << "-1\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << t[(i - 1) * m + j] << " \n"[j == m];
        }
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