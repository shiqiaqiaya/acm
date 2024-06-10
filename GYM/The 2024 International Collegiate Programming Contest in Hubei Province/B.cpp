#include<bits/stdc++.h>
using namespace std;
#define int long long
#define point array<int, 2>

point operator+(point a, point b) {
    return {a[0] + b[0], a[1] + b[1]};
}

point operator-(point a, point b) {
    return {a[0] - b[0], a[1] - b[1]};
}

int operator*(point a, point b) {
    return a[0] * b[1] - a[1] * b[0];
}

void QWQ() {

}

void QAQ() {
    int n;
    cin >> n;

    vector<point> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1];
    }

    double ans = 4e18;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if ((a[k] - a[i]) * (a[j] - a[i]) != 0) {
                    ans = min(ans, 1.0 * abs(((a[k] - a[i]) * (a[j] - a[i]))) / 2);
                }
            }
        }
    }

    if (ans == 4e18) {
        cout << "-1\n";
        return;
    }

    cout << fixed << setprecision(12);
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