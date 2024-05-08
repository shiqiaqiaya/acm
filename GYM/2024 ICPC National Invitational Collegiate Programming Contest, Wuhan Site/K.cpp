#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> pre(1e6 + 1), f(1e6 + 1);

void QWQ() {
    for (int i = 1; i <= 1e6; i++) {
        pre[i] = pre[i - 1] ^ i;
        if (pre[i] == 0) {
            f[i] = 0;
            continue;
        }
        if (f[i - 1] == 0) {
            f[i] = 1;
        } else {
            if ((pre[i] ^ 1) == 0) {
                f[i] = 1;
            } else {
                if (i & 1) {
                    f[i] = 1;
                } else {
                    f[i] = 0;
                }
            }
        }
    }
}

void QAQ() {
    int n;
    cin >> n;

    if (f[n]) {
        cout << "Fluttershy\n";
    } else {
        cout << "Pinkie Pie\n";
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