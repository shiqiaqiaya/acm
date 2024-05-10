#include <bits/stdc++.h>
using namespace std;
#define int long long
#define point array<int, 2>  //点/向量

const double pi = acos(-1);

point operator+(point a, point b) {
    return {a[0] + b[0], a[1] + b[1]};
}
point operator-(point a, point b) {
    return {a[0] - b[0], a[1] - b[1]};
}
double operator*(point a, point b) {    //叉积
    return a[0] * b[1] - a[1] * b[0];
}
double operator&(point a, point b) {    //点积
    return a[0] * b[0] + a[1] * b[1];
}

auto get_theta = [](point a) {  //计算极角
    return a[1] < 0 ? 2 * pi + atan2(a[1], a[0]) : atan2(a[1], a[0]);
};

auto get_angle = [](point a, point b) { //计算俩向量夹角
    auto t1 = get_theta(a), t2 = get_theta(b);
    return min(fabs(t1 - t2), 2 * pi - fabs(t1 - t2));
};

auto get_quadrant = [](point a) {   //计算象限,在坐标轴上需要另外考虑
    return (((a[1] < 0) << 1) | (a[0] < 0) ^ (a[1] < 0)) + 1;
};

auto polar_sort = [](vector<int> & id, point c = {0, 0}, vector<point> & p) {   //绕c进行极角排序
    sort(id.begin() + 1, id.end(), [&](auto & t1, auto & t2) {
        auto & x = p[t1], & y = p[t2];
        return (get_quadrant(x - c) < get_quadrant(y - c)) || (get_quadrant(x - c) == get_quadrant(y - c) && (((x - c) * (y - c)) > 0));
    });
};

void QWQ() {

}

void QAQ() {
    int n;
    cin >> n;

    vector<point> p(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> p[i][0] >> p[i][1];
    }

    vector<point> ans(1);
    vector<int> vis(n + 1);

    auto andrew = [&](vector<point> & p, int n) {
        vector<int> stk(n + 2), used(n + 2);	//第一个点会重复
        int top = 0;

        sort(p.begin() + 1, p.end());	//排序

        stk[++top] = 1;	//加入起点

        for (int i = 2; i <= n; i++) {	//求下凸壳
            while (top >= 2 && (p[stk[top - 1]] - p[stk[top]]) * (p[i] - p[stk[top]]) >= 0) {
                used[stk[top--]] = 0;	//=0即在凸包边上删去
            }
            stk[++top] = used[i] = i;
        }

        int tmp = top;	//保留下凸壳

        for (int i = n - 1; i; i--) {	//求上凸壳
            if (!used[i]) {
                while (top > tmp && (p[stk[top - 1]] - p[stk[top]]) * (p[i] - p[stk[top]]) >= 0) {
                    used[stk[top--]] = 0;
                }
                stk[++top] = used[i] = i;
            }
        }

        for (int i = 1; i < top; i++) {	//  最后一个点不加,最后一个等于第一个
            vis[stk[i]] = 1;
            ans.push_back(p[stk[i]]);	//记录凸包
        }
    };

    andrew(p, n);

    int res = 1;

    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            continue;
        }
        vector<int> id(1);
        for (int j = 1; j <= n; j++) {
            if (j == i) continue;
            id.push_back(j);
        }
        polar_sort(id, p[i], p);
        int lst = 0, cnt = 0;
        for (int j = 1; j < n; j++) {
            if (vis[id[j]]) {
                if (lst) {
                    res += cnt == 0;
                }
                lst = j;
                cnt = 0;
            } else if (lst) {
                cnt++;
            }
        }
        for (int j = 1; j < n; j++) {
            if (vis[id[j]]) {
                if (lst) {
                    res += cnt == 0;
                }
                break;
            } else if (lst) {
                cnt++;
            }
        }
    }

    cout << res << "\n";
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