    #include<bits/stdc++.h>
    using namespace std;
    #define int long long

    void QAQ() {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        s = " " + s;

        int end_cnt = 0, ok = 0, cnt = 0;

        vector<int> vis(n + 1);

        for (int i = n; ~i; i--) {
            if (!ok) {
                if (s[i] == s.back()) {
                    if (end_cnt == k) {
                        cout << "-1\n";
                        return;
                    }
                    end_cnt++;
                } else {
                    ok = 1;
                    vis[i] = 1;
                    (cnt += 1) %= k;
                }
            } else {
                vis[i] = !cnt;
                if ((i + k <= n && s[i] != s[i + k]) || (i + k > n && s[i] != s.back())) {
                    (cnt += 1) %= k;
                } else {
                    break;
                }
            }
        }

        s += ((s.back() - '0') ^ (end_cnt == k)) + '0';

        if (end_cnt == k && k == n) {
            cout << n << "\n";
            return;
        }

        for (int i = 1; i <= n; i++) {
            if ((i <= k && s[i] == s[1]) || (i > k && s[i] != s[i - k])) {
                if (vis[i] && s[i] == s.back() && i % k + end_cnt == k) {
                    cout << i << "\n";
                    return;
                }
            } else {
                break;
            }
        }

        cout << "-1\n";
    }

    signed main() {
        cin.tie(0) -> sync_with_stdio(0);
        int t = 1;
        cin >> t;

        while (t--) {
            QAQ();
        }
    }