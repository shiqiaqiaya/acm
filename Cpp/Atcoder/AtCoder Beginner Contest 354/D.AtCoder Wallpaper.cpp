#include <bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ta = (a % 4 + 4) % 4, tb = (b % 2 + 2) % 2, tc = ta - a + c, td = tb - b + d;

    auto get = [&](int x, int y) {
        int tx = x % 4, ty = y % 2;
        int sum = 0;

        if (tx == 1) {
            sum = 3;
        } else if (tx == 2) {
            sum = 6;
        } else if (tx == 3) {
            sum = 7;
        }

        sum += (x / 4) * 8;
        sum *= (y / 2);

        if (ty) {
            if (tx == 1) {
                sum += 2;
            } else if (tx == 2) {
                sum += 3;
            } else if (tx == 3) {
                sum += 3;
            }

            sum += (x / 4) * 4;
        }

        return sum;
    };

    int sum1 = 0, sum2 = 0;


    if (tc % 4 == 1) {
        sum2 = 3;
    } else if (tc % 4 == 2) {
        sum2 = 6;
    } else if (tc % 4 == 3) {
        sum2 = 7;
    }

    sum2 += (tc / 4) * 8;

    cout << get(tc, td) - get(ta, td) - get(tc, tb) + get(ta, tb) << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;

    QWQ();

    while (t--) {
        QAQ();
    }
}