#include<bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n;
    cin >> n;

    auto norm = [&](int x) {
        return (x - 1 + n) % n + 1;
    };

    auto query = [&](int x) {
        cout << "? " << norm(x) << endl;
        cin >> x;
        return x;
    };

    auto answer = [&](int a, int b) {
        cout << "! " << norm(a) << " " << norm(b) << endl;
    };

    int q1 = query(1), q2 = query(2);

    if (q1 == q2) {
        int l = 2, r = q1 + 1;

        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (query(mid) == q1) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        if (q1 <= n / 2) {
            answer(l - q1, l);
        } else {
            int d = n - q1;
            int x = l + (n - 2 * d + 1) / 2;
            int y = x + d;
            answer(x, y);
        }
    } else if (q1 - q2 == 1) {
        int d = n - q1;
        int x = 2 + (q2 - d) / 2;
        int y = x + d;
        answer(x, y);
    } else if (q1 - q2 == -1) {
        int d = n - q2;
        int x = 1 - (q1 - d) / 2;
        int y = x - d;
        answer(x, y);
    } else if (q1 - q2 == 2) {
        int d = query(1 + q1 / 2);
        int x = 1 + (q1 - d) / 2;
        int y = x + d;
        answer(x, y);
    } else if (q1 - q2 == -2) {
        int d = query(2 - q2 / 2);
        int x = 2 - (q2 - d) / 2;
        int y = x - d;
        answer(x, y);
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