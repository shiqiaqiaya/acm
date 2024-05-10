#include <bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int la, ra, lb, rb;
    cin >> la >> ra >> lb >> rb;

    set<int> t1, t2;

    for (int i = la; i <= ra; i++) {
        if (t1.size() == 10) {
            break;
        }
        t1.insert(i % 10);
    }

    for (int i = lb; i <= rb; i++) {
        if (t2.size() == 10) {
            break;
        }
        t2.insert(i % 10);
    }

    if (t1.size() == 10 || t2.size() == 10) {
        cout << 9 << "\n";
    } else {
        char res = '0';
        for (int i = la; i <= ra; i++) {
            for (int j = lb; j <= rb; j++) {
                int t = i + j;
                string tmp = to_string(t);
                res = max(res, *max_element(tmp.begin(), tmp.end()));
            }
        }
        cout << res << "\n";
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