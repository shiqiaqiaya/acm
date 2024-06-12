#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long

void QAQ() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n + 1);

    int end_i = 0, end_j = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = " " + a[i];
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != '*') {
                end_i = i, end_j = j;
            }
        }
    }

    unordered_map<int, int> dp;
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        auto get = [&](int state, int k) {
            return state >> 2 * k & 3;
        };
        auto set = [&](int state, int k, int v) {
            return state & (~(3ll << 2 * k)) | (v << 2 * k);
        };
        auto roll = [&]() {
            unordered_map<int, int> dpn;
            for (auto & [x, cnt] : dp) {
                dpn[x << 2] += cnt;
            }
            swap(dpn, dp);
        };

        roll();

        for (int j = 1; j <= m; j++) {
            unordered_map<int, int> dpn;
            for (auto & [mask, cnt] : dp) {
                int lt = get(mask, j - 1), up = get(mask, j);
                if (a[i][j] == '*') {
                    if (!lt && !up) {
                        dpn[mask] += cnt;
                    }
                } else {
                    if (!lt && !up) {
                        if (i + 1 <= n && a[i + 1][j] != '*' && j + 1 <= m && a[i][j + 1] != '*') {
                            dpn[set(set(mask, j - 1, 1), j, 2)] += cnt;
                        }
                    } else if (!lt || !up) {
                        int t = lt | up;
                        if (i + 1 <= n && a[i + 1][j] != '*') {
                            dpn[set(set(mask, j - 1, t), j, 0)] += cnt;
                        } if (j + 1 <= m && a[i][j + 1] != '*') {
                            dpn[set(set(mask, j - 1, 0), j, t)] += cnt;
                        }
                    } else {
                        int state = set(set(mask, j - 1, 0), j, 0);
                        if (lt == 1 && up == 1) {
                            for (int u = j, s = 0; ; u++) {
                                int z = get(mask, u);
                                if (z == 1) {
                                    s++;
                                } else if (z == 2) {
                                    if (--s == 0) {
                                        dpn[set(state, u, 1)] += cnt;
                                        break;
                                    }
                                }
                            }
                        } else if (lt == 2 && up == 2) {
                            for (int u = j - 1, s = 0; ; u--) {
                                int z = get(mask, u);
                                if (z == 1) {
                                    if (++s == 0) {
                                        dpn[set(state, u, 2)] += cnt;
                                        break;
                                    }
                                } else if (z == 2) {
                                    s--;
                                }
                            }
                        } else if (lt == 2 && up == 1) {
                            dpn[state] += cnt;
                        } else if (lt == 1 && up == 2 && i == end_i && j == end_j) {
                            dpn[state] += cnt;
                        }
                    }
                }
            }
            swap(dpn, dp);
        }
    }

    cout << dp[0] << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;

    while (t--) {
        QAQ();
    }
}