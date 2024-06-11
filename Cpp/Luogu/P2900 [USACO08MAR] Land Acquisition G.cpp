#include<bits/stdc++.h>
using namespace std;
#define int long long

#define point array<int, 2>  //点/向量

point operator+(point a, point b) {
    return {a[0] + b[0], a[1] + b[1]};
}
point operator-(point a, point b) {
    return {a[0] - b[0], a[1] - b[1]};
}
point operator*(point a, int k) {
    return {a[0] * k, a[1] * k};
}
point operator/(point a, int k) {
    return {a[0] / k, a[1] / k};
}
int operator*(point a, point b) {    //叉积
    return a[0] * b[1] - a[1] * b[0];
}
int operator&(point a, point b) {    //点积
    return a[0] * b[0] + a[1] * b[1];
}

void QAQ() {
    int n;
    cin >> n;

    vector<array<int, 2>> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1];
    }

    a = [&]() {
        vector<array<int, 2>> ta(1);

        sort(a.begin() + 1, a.end(), [&](auto & x, auto & y) {
            return x[0] < y[0] || x[0] == y[0] && x[1] < y[1];
        });

        int now = 0;

        for (int i = n; i; i--) {
            if (a[i][1] > now) {
                now = a[i][1];
                ta.push_back(a[i]);
            }
        }

        sort(ta.begin() + 1, ta.end(), [&](auto & x, auto & y) {
            return x[0] < y[0] || x[0] == y[0] && x[1] < y[1];
        });

        return ta;
    } ();

    n = a.size() - 1;
    vector<int> dp(n + 1);
    deque<point> q;
    q.push_back({a[1][1], 0});

    //斜率单调递增，新加的点的横坐标也单调递增
    for (int i = 1; i <= n; i++) {
        point tmp = {1, - a[i][0]};  //随便设一条平行的向量
        while (q.size() >= 2 && (q[1] - q[0]) * tmp >= 0) {
            q.pop_front();
        }
        dp[i] = q[0][1] - tmp[1] * q[0][0];
        if (i + 1 > n) break;
        tmp = {a[i + 1][1], dp[i]};    //新加入的点
        while (q.size() >= 2 && (tmp - q[q.size() - 2]) * (q[q.size() - 1] - q[q.size() - 2]) <= 0) {
            q.pop_back();
        }
        q.push_back(tmp);
    }

    cout << dp[n] << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;

    while (t--) {
        QAQ();
    }
}