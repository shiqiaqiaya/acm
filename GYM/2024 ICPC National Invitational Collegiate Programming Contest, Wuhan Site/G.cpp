#include <bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

auto exgcd = [](auto exgcd, int a, int b, int & x, int & y) -> int {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(exgcd, b, a % b, y, x);
    y -= a / b * x;
    return d;
};

auto LiEu = [](int a, int b, int n, int & x, int & k) {	//n为模数,x为a的系数,k为n的系数
    int d = exgcd(exgcd, a, n, x, k);
    if (b % d != 0) {
        return (int)0;	//无解
    }
    int t = n / d;
    x = (((b / d * x) % t) + t) % t;
    k = (b - a * x) / n;
    return d;
};

void QAQ() {
    int n, m, a, b, k;
    cin >> n >> m >> a >> b >> k;

    int x, y, d = LiEu(a, k, b, x, y);

    int dx = b / d, dy = a / d;

    auto work = [&](int n, int m, int x, int y, int dx, int dy) {
        [&]() {
            int t = x % dx;
            t = (x - t) / dx;
            x -= t * dx, y += t * dy;
        } ();

        auto get = [&](int x, int y) {
            if (x < 0 || y < 0) return n + m;
            if (!x) return n + m - y * (m / y);
            if (!y) return n + m - x * (n / x);
            return n + m - (x + y) * min(n / x, m / y);
        };

        int ans = get(x, y);

        if (!x) {
            x += dx, y -= dy;
        }

        for (int r; x <= n && y > 0; ) {
            r = n / (n / x);
            int t = n / x;
            t = ceil((1.0 * y * t - m) / (t * dy));
            ans = min({ans, get(x, y), get(x + t * dx, y - t * dy)});
            t = ceil((1.0 * (r + 1) - x) / dx);
            x = x + t * dx, y = y - t * dy;
        }

        return ans;
    };

    int ans = min(work(n, m, x, y, dx, dy), work(m, n, y, x, dy, dx));

    cout << ans << "\n";
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