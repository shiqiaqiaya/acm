#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> base = {131, 233}, mod = {1'000'000'007, 998'244'353};

struct Hash {	//双哈希
    vector<vector<int>> pre, pw;
    Hash(string s = " ") {	// 传入的 s 必须重 1 开始
        pre = vector(s.size(), vector<int>(base.size())), pw = vector(s.size(), vector<int>(base.size(), 1));
        for (int i = 1; i < s.size(); i++) {
            for (int _ = 0; _ < base.size(); _++) {
                (pre[i][_] = pre[i - 1][_] * base[_] + s[i]) %= mod[_];
                (pw[i][_] = pw[i - 1][_] * base[_]) %= mod[_];
            }
        }
    }

    vector<int> query(int l, int r, vector<int> res = vector<int>(base.size())) {
        for (int _ = 0; _ < base.size(); _++) {
            (((res[_] = pre[r][_] - pre[l - 1][_] * pw[r - l + 1][_]) %= mod[_]) += mod[_]) %= mod[_];
        }
        return res;
    }
};

void QAQ() {
    string s;
    cin >> s;

    if (string(s.size(), 'a') == s) {
        cout << s.size() - 1 << "\n";
        return;
    }

    int n = s.size();

    s = " " + s;

    Hash hs(s);

    vector<int> suf(n + 1);

    int cnt = 0;

    for (int i = n; i; i--) {
        if (s[i] == 'a') {
            suf[i] = ++cnt;
        } else {
            cnt = 0;
        }
    }
    cnt = 0;
    int ok = 0, ans = 0;
    for (int len = 1; len <= n; len++) {
        if (!ok && s[len] == 'a') {
            cnt++;
        } else if (!ok) {
            ok = 1;
        }

        if (len == 1 && s[len] == 'a') {
            continue;
        }
        if (ok) {
            ans += [&]() {
                auto tmp = hs.query(cnt + 1, len);
                int mx = cnt;

                for (int pos = len; ; ) {
                    auto tt = hs.query(pos - (len - cnt) + 1, pos);

                    if (tt != tmp) {
                        return 0ll;
                    }

                    int tpos = pos + 1;
                    if (tpos <= n) {
                        if (suf[tpos] + pos == n) {
                            break;
                        } else {
                            pos = pos + suf[tpos] + len - cnt;
                            mx = min(mx, suf[tpos]);
                            if (pos > n) {
                                return 0ll;
                            }
                        }
                    } else {
                        break;
                    }
                }

                return mx + 1;
            } ();
        }
    }

    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    while (t--) {
        QAQ();
    }
}