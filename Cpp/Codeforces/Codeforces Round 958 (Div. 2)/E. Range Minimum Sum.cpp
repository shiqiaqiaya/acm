#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n;
    cin >> n;

    vector<int> a(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<array<int, 2>> L(n + 2), R(n + 2);
    vector<vector<int>> stk(2);

    for (int i = 0; i <= n + 1; i++) {
        vector<int> tmp;
        while (stk[1].size() && a[stk[1].back()] > a[i]) {
            R[stk[1].back()][1] = i;
            stk[1].pop_back();
        } while (stk[0].size() && a[stk[0].back()] > a[i]) {
            tmp.push_back(stk[0].back());
            R[stk[0].back()][0] = i;
            stk[0].pop_back();
        }
        stk[0].push_back(i);
        stk[1].insert(stk[1].end(), tmp.rbegin(), tmp.rend());
    }
    for (int i = n + 1; ~i; i--) {
        vector<int> tmp;
        while (stk[1].size() && a[stk[1].back()] > a[i]) {
            L[stk[1].back()][1] = i;
            stk[1].pop_back();
        } while (stk[0].size() && a[stk[0].back()] > a[i]) {
            tmp.push_back(stk[0].back());
            L[stk[0].back()][0] = i;
            stk[0].pop_back();
        }
        stk[0].push_back(i);
        stk[1].insert(stk[1].end(), tmp.rbegin(), tmp.rend());
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans += a[i] * (i - L[i][0]) * (R[i][0] - i);
    }

    vector<int> res(n + 2, ans), tmp(n + 2);

    for (int i = 1; i <= n; i++) {
        res[i] -= a[i] * (i - L[i][0]) * (R[i][0] - i);
        res[i] -= tmp[L[i][0]];
        res[L[i][0]] += a[i] * (L[i][0] - L[i][1] - (L[i][0] != 0)) * (R[i][0] - i);
        tmp[i] = tmp[L[i][0]] + (i - L[i][0]) * a[i];
    }
    tmp = vector<int>(n + 2);
    for (int i = n; i; i--) {
        res[i] -= tmp[R[i][0]];
        res[R[i][0]] += a[i] * (R[i][1] - R[i][0] - (R[i][0] != n + 1)) * (i - L[i][0]);
        tmp[i] = tmp[R[i][0]] + (R[i][0] - i) * a[i];
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << " \n"[i == n];
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