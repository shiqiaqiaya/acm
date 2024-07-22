#include <bits/stdc++.h>
#define int long long
using namespace std;

void QAQ() {
	int n, x, y;
	cin >> n >> x >> y;

	vector<int> a(n + 1, 1);
    int now = 1;

	for (int i = y - 1; i; i--) {
		a[i] = (now *= -1);
	}
    now = 1;
	for (int i = x + 1; i <= n; i++) {
		a[i] = (now *= -1);
	}

	for (int i = 1; i <= n; i++) {
		cout << a[i] << " \n"[i == n];
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