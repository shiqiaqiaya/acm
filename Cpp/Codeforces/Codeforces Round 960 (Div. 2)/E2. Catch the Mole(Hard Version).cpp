#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> fa(n + 1), h(n + 1);
	vector<vector<int>> e(n + 1);

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	int t = 71;

	auto query = [&](int x) -> int {
		cout << "? " << x << endl;
		int res;
		cin >> res;
		return res;
	};

	for (int i = 2; i <= n; i++) {
		if (e[i].size() == 1) {
			for (int j = 0; j < t; j++) {
				if (query(i) == 1) {
					cout << "! " << i << endl;
					return;
				}
			}
			break;
		}
	}

	auto dfs = [&](auto &&self, int x, int f = 0) -> void {
		h[x] = 1;
		fa[x] = f;
		for (auto y : e[x]) {
			if (y == f) continue;
			self(self, y, x);
			h[x] = max(h[x], h[y] + 1);
		}
	};

	dfs(dfs, 1);

	auto dfs1 = [&](auto &&self, int x, int f = 0) -> int {
		vector<int> ee;
		for (auto y : e[x]) {
			if (y == f || h[y] < t) continue;
			ee.push_back(y);
		}

		for (auto y : ee) {
			if (y == ee.back() || query(y) == 1) return self(self, y, x);
		}

		return x;
	};	

	int x = dfs1(dfs1, 1);
	// cerr << x << "\n";
	vector<int> a;
	for (int i = x; i; i = fa[i]) {
		a.push_back(i);
	}

	int L = 0, R = a.size() - 1;

	while (L < R) {
		int mid = L + R >> 1;
		if (query(a[mid]) == 1) {
			R = mid;
		} else {
			L = mid + 1;
            R = min((int)a.size() - 1, R + 1);
            L = min((int)a.size() - 1, L + 1);
		}
	}

	cout << "! " << a[R] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}