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
    int n, L;
    cin >> n >> L;

    vector<int> c(n + 1), sum(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        sum[i] = sum[i - 1] + c[i];
    }

    deque<point> q;
    q.push_back({0, 0});
    vector<int> dp(n + 1);

    //斜率不单调，但新加的点横坐标单调递增
    for (int i = 1; i <= n; i++) {
        point tmp = {1, 2 * (i + sum[i] - 1 - L)};  //随便设一条平行的向量

        int l = 0, r = q.size() - 1;

        auto chk = [&](int mid) {   //二分查
            return mid == 0 || (q[mid] - q[mid - 1]) * tmp >= 0;
        };

        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (chk(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        dp[i] = q[l][1] - tmp[1] * q[l][0] + tmp[1] * tmp[1] / 4;
        tmp = {i + sum[i], dp[i] + (i + sum[i]) * (i + sum[i])};    //新加入的点
        while (q.size() >= 2 && (tmp - q[q.size() - 2]) * (q[q.size() - 1] - q[q.size() - 2]) >= 0) {
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