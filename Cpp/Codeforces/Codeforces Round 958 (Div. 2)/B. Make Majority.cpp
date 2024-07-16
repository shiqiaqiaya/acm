#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
	int n;
	cin >> n;

	string s, t;
	cin >> s;

	for (int i = 0; i < n; i++) {
		if (s[i] == '1') t.push_back('1');
		else {
			t.push_back('0');
			while (i + 1 < n && s[i + 1] == '0') i++;
		}
	}

	if (count(t.begin(), t.end(), '0') < count(t.begin(), t.end(), '1')) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
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