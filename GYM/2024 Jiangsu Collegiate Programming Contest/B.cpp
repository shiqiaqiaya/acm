#include <bits/stdc++.h>
using namespace std;
#define int long long

#define point array<double, 2>  //点/向量

const double pi = acos(-1);

point operator+(point a, point b) {
    return {a[0] + b[0], a[1] + b[1]};
}
point operator-(point a, point b) {
    return {a[0] - b[0], a[1] - b[1]};
}
point operator*(point a, double k) {
    return {a[0] * k, a[1] * k};
}
point operator/(point a, double k) {
    return {a[0] / k, a[1] / k};
}
double operator*(point a, point b) {    //叉积
    return a[0] * b[1] - a[1] * b[0];
}
double operator&(point a, point b) {    //点积
    return a[0] * b[0] + a[1] * b[1];
}

struct line {   //线
    point p, v; //p为起点,v为方向向量
};

struct circle { //圆
    point c;    //圆心
    double r;   //半径
};

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

auto rotat = [](point a, double theta) {  //将向量a绕起点逆时针旋转theta
    return point{a[0] * cos(theta) - a[1] * sin(theta), a[1] * cos(theta) + a[0] * sin(theta)};
};

auto on_left = [](point p, line a) {   //判断p点是否在直线a的左侧
    return a.v * (p - a.p) > 0;  //在直线上时=0
};  

//(a.v * b.v) = 0时两直线平行或重合
auto get_line_intersection = [](line a, line b) {   //计算俩直线交点
    auto o = a.p - b.p;
    auto t = (b.v * o) / (a.v * b.v);
    return a.p + a.v * t;
};

auto distance_to_line = [](point p, line a) {   //点到直线距离
    return fabs(a.v * (p - a.p)) / sqrt(a.v & a.v);
};

auto distance_to_segment = [](point p, line a) {    //点到线段距离
    if ((a.v & a.v) == 0) return sqrt((p - a.p) & (p - a.p));
    auto v2 = p - a.p, v3 = p - a.p - a.v;
    if ((a.v & v2) < 0) return sqrt(v2 & v2);
    if ((a.v & v3) > 0) return sqrt(v3 & v3);
    return distance_to_line(p, a);
};

auto get_line_projection = [](point p, line a) {    //求点在直线上的射影,即垂足
    return a.p + a.v * (a.v & (p - a.p) / (a.v & a.v));
};

auto on_segment = [](point p, line a) { //判断点是否在线段上
    return ((p - a.p) * a.v == 0) && (((p - a.p) & (p - a.p - a.v)) <= 0);
};

auto segment_intersection = [](line a, line b) {    //判断俩线段是否相交
    //快速排斥
    if (min(a.p[0], (a.p + a.v)[0]) <= max(b.p[0], (b.p + b.v)[0]) && 
        min(b.p[0], (b.p + b.v)[0]) <= max(a.p[0], (a.p + a.v)[0]) && 
        min(a.p[1], (a.p + a.v)[1]) <= max(b.p[1], (b.p + b.v)[1]) &&
        min(b.p[1], (b.p + b.v)[1]) <= max(a.p[1], (a.p + a.v)[1])
    )
    //跨立实验
    return (a.v * (b.p - a.p)) * (a.v * (b.p + b.v - a.p)) <= 0 && (b.v * (a.p - b.p)) * (b.v * (a.p + a.v - b.p)) <= 0;
};

auto polygon_contain = [](vector<point> & polygon, point p) {   //判断点是否在任意多边形内(可能为错)
    //(可能需要先判断点是否在多边形边上或点上)
    int n = polygon.size() - 1, crossings = 0;
    for (int i = 1; i <= n; i++) {
        crossings += (((polygon[i][0] <= p[0]) == (p[0] < polygon[i % n + 1][0])) && 
        ((p[1] - polygon[i][1]) * (polygon[i % n + 1][0] - polygon[i][0]) < (polygon[i % n + 1][1] - polygon[i][1]) * (p[0] - polygon[i][0])));
    }
    return crossings % 2 == 1;
};

auto convex_polygon = [](vector<point> & polygon, point p) {    //判断点是否在凸边形内
    int n = polygon.size() - 1;
    for (int i = 1; i <= n; i++) {
        if (!on_left(p, line{polygon[i], polygon[i % n + 1] - polygon[i]})) {
            return false;
        }
    }
    return true;
};

auto polar_sort = [](vector<point> & p, point c = {0, 0}) {   //绕c进行极角排序
    sort(p.begin() + 1, p.end(), [&](auto x, auto y) {
        return (get_quadrant(x - c) < get_quadrant(y - c)) || (get_quadrant(x - c) == get_quadrant(y - c) && (((x - c) * (y - c)) > 0));
    });
};

void QWQ() {

}

void QAQ() {
    int r;
    cin >> r;

    vector<array<int, 2>> a(6);

    for (int i = 1; i <= 5; i++) {
        cin >> a[i][0];
    }

    for (int i = 1; i <= 5; i++) {
        cin >> a[i][1];
    }

    double ans = pi * r * r;

    auto get_point = [&](int theta) {
        return point{r * cos(theta * pi / 180), r * sin(theta * pi / 180)};
    };

    for (int i = 1; i <= 5; i++) {
        double theta = ((a[i % 5 + 1][0] - a[i][1] + 360) % 360) * pi / 180;
        ans -= (theta - sin(theta)) * r * r / 2;
        line t1 = {get_point(a[i][1]), (get_point(a[(i + 1) % 5 + 1][0]) - get_point(a[i][1]))};
        line t2 = {get_point(a[i % 5 + 1][0]), (get_point(a[(i + 3) % 5 + 1][1]) - get_point(a[i % 5 + 1][0]))};
        auto c = get_line_intersection(t1, t2);
        ans -= (get_point(a[i][1]) - c) * (get_point(a[i % 5 + 1][0]) - c) / 2;
    }

    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cout << fixed << setprecision(12);

    int t = 1;
    cin >> t;

    QWQ();

    while (t--) {
        QAQ();
    }
}