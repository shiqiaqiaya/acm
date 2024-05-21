#include<bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n, q;
    cin >> n >> q;

    vector<int> a(1), pos(n + 1);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        while (x) {
            a.push_back(x);
            x >>= 1;
        }

        a.push_back(x);
        pos[i] = a.size() - 1;
    }

    vector<array<int, 3>> qer(q + 1);

    for (int i = 1; i <= q; i++) {
        cin >> qer[i][0] >> qer[i][1] >> qer[i][2];
        qer[i][0] = pos[qer[i][0] - 1] + 1, qer[i][1] = pos[qer[i][1]], qer[i][2]++;
    }

    auto ans = [&](int n, int q, int mn, int mx) -> vector<int> {
        vector<array<int, 2>> pos(1);   //记录端点
        vector<int> ans(q + 1), cnt(q + 1), id(n + 1);  //cnt 为求出当前 mid 第几大，id 为区间划分

        for (int i = 1; i <= q; i++) {
            pos.push_back({qer[i][0] - 1, i}), pos.push_back({qer[i][1], i});
        }

        iota(id.begin(), id.end(), 0ll);
        sort(pos.begin(), pos.end());

        auto slove = [&](auto & slove, int l, int r, int al, int ar, int ql, int qr) {
            if (l == r || al > ar || ql > qr) {
                for (int i = ql; i <= qr; i++) {
                    ans[pos[i][1]] = l;
                }
                return;
            }

            int mid = l + r >> 1, am = stable_partition(id.begin() + al, id.begin() + ar + 1, [&](auto & i) {
                return a[i] <= mid;
            }) - id.begin() - 1;    //划分区间

            for (int i = ql, j = am + 1; i <= qr; i++) {    //求第 k 大 j 从 am + 1 开始
                while (j <= ar && id[j] <= pos[i][0]) { //求第 k 大到 ar 结束，一定要 <=
                    j++;
                }
                if (pos[i][0] + 1 == qer[pos[i][1]][0]) {
                    cnt[pos[i][1]] -= j;
                } else {
                    cnt[pos[i][1]] += j;
                }
            }

            int qm = stable_partition(pos.begin() + ql, pos.begin() + qr + 1, [&](auto & x) {
                return qer[x[1]][2] > cnt[x[1]];
            }) - pos.begin() - 1;   //划分询问

            for (int i = ql; i <= qm; i++) {    //更新左，若求第 k 大时与更新右交换写法
                qer[pos[i][1]][2] -= cnt[pos[i][1]], cnt[pos[i][1]] = 0;
            }
            for (int i = qm + 1; i <= qr; i++) {    //更新右
                cnt[pos[i][1]] = 0;
            }

            slove(slove, l, mid, al, am, ql, qm), slove(slove, mid + 1, r, am + 1, ar, qm + 1, qr);
        };

        slove(slove, mn, mx, 1, n, 1, 2 * q);

        return ans;
    } (a.size() - 1, q, 0, 1e5);

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << "\n";
    }
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