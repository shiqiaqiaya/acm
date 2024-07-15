#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, SUM = 0;
    cin >> n;

    vector<array<int, 3>> t(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> t[i][0];
        SUM += t[i][0];
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i][1];
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i][2];
    }
    array<array<int, 2>, 3> res;

    auto F = [&](int a, int b, int c) {
        int sum = 0;
        int i, ok = 0;
        for (i = 1; i <= n; i++) {
            sum += t[i][a];
            if (sum * 3 >= SUM) {
                ok = 1;
                break;
            }
        }
        res[a] = {1, i};
        if (ok == 0) return 0;
        sum = 0, ok = 0;
        res[b] = {i + 1, 0};
        for (i = i + 1; i <= n; i++) {
            sum += t[i][b];
            if (sum * 3 >= SUM) {
                ok = 1;
                break;
            }
        }
        res[b][1] = i;
        if (ok == 0) return 0;
        sum = 0, ok = 0;
        res[c][0] = i + 1;
        for (i = i + 1; i <= n; i++) {
            sum += t[i][c];
            if (sum * 3 >= SUM) {
                ok = 1;
                break;
            }
        }
        res[c][1] = i;
        if (ok == 0) return 0;
        return 1;
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (i == j || j == k || i == k) continue;
                if (F(i, j, k)) {
                    cout << res[0][0] << " " << res[0][1] << " " << res[1][0] << " " << res[1][1] << " " << res[2][0] << " " << res[2][1] << "\n";
                    return;
                }
            }
        }
    }
    cout << "-1\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}