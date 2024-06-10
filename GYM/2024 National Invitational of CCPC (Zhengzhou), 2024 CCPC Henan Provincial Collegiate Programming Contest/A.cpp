#include<bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int n, d;
    cin >> n >> d;

    int t = stol("1234567890") + d;
    for (int i = to_string(n).size(); i; i--) {
        t *= 10;
    }
    cout << (int)ceil(1.0 * t / n) << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}