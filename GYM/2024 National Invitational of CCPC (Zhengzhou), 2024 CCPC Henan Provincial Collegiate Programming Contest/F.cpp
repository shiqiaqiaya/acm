#include<bits/stdc++.h>
using namespace std;
#define int long long

void QWQ() {

}

void QAQ() {
    int ans = 0, n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;
        if (s.size() == 5 && s[2] == s.back() && (set<char>(s.begin(), s.begin() + 5)).size() == 4) {
            ans++;
        }
    }

    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;

    while (t--) {
        QAQ();
    }
}