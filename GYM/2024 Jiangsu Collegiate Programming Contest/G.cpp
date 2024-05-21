#include<bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int b, a1, a2, t1, t2;
    cin >> b >> t1 >> a1 >> t2 >> a2;

    cout << fixed << setprecision(12);

    if ((t2 - t1) * b >= a1) {
        cout << (double)a1 / b << " " << (double)a2 / b << "\n";
    } else if (a2 >= (a1 - (t2 - t1) * b)) {
        cout << (t2 - t1) + (double)(a1 - (t2 - t1) * b) * 2 / b << " ";
        cout << (double)(a2 - (a1 - (t2 - t1) * b) + (a1 - (t2 - t1) * b) * 2) / b << "\n";
    } else {
        cout << (double)(a1 + a2) / b << " ";
        cout << (double)a2 * 2 / b << "\n";
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