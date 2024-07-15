#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = " " + a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] = " " + b[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if ((b[i][j] - a[i][j] + 3) % 3 == 0) {

            } else if ((b[i][j] - a[i][j] + 3) % 3 == 1) {
                int t = a[i][j] - '0';
                (t += 1) %= 3;
                a[i][j] = t + '0';
                t = a[i + 1][j] - '0';
                (t += 2) %= 3;
                a[i + 1][j] = t + '0';
                t = a[i + 1][j + 1] - '0';
                (t += 1) %= 3;
                a[i + 1][j + 1] = t + '0';
                t = a[i][j + 1] - '0';
                (t += 2) %= 3;
                a[i][j + 1] = t + '0';
            } else if ((b[i][j] - a[i][j] + 3) % 3 == 2) {
                int t = a[i][j] - '0';
                (t += 2) %= 3;
                a[i][j] = t + '0';
                t = a[i + 1][j] - '0';
                (t += 1) %= 3;
                a[i + 1][j] = t + '0';
                t = a[i + 1][j + 1] - '0';
                (t += 2) %= 3;
                a[i + 1][j + 1] = t + '0';
                t = a[i][j + 1] - '0';
                (t += 1) %= 3;
                a[i][j + 1] = t + '0';
            }
        }
    }

    if (a == b) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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