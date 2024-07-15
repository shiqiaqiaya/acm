#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int l = 0, r = 2e9;

    auto chk = [&](int mid, int res = 0) {
        struct trie_node {
            array<int, 2> son = {};    //son是看字符
            int exist = 0;  //记录以该节点结尾的字符串个数
        };

        vector<trie_node> tr(1);

        auto insert = [&](int i) {
            int p = 0;
            for (int bit = 31; ~bit; bit--) {
                int c = a[i] >> bit & 1;
                if (!tr[p].son[c]) {
                    tr[p].son[c] = tr.size();   //若没有就添加节点
                    tr.push_back({});
                }
                p = tr[p].son[c];   //向下查
                tr[p].exist = max(tr[p].exist, i);
            }
        };

        int tmp = 0;

        auto find = [&](int s) {
            int p = 0;
            for (int bit = 31; ~bit; bit--) {
                int c = (s ^ mid) >> bit & 1;
                if ((mid >> bit & 1) && tr[p].son[c ^ 1]) {
                    tmp = max(tmp, tr[tr[p].son[c ^ 1]].exist);
                }
                if (!tr[p].son[c]) {
                    break;
                }
                p = tr[p].son[c];
            }
        };

        for (int i = 1; i <= n; i++) {
            find(a[i]);
            res += tmp;
            insert(i);
        }
        return res < k;
    };

    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (chk(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << l << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}