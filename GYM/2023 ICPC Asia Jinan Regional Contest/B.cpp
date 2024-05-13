#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;

void QWQ() {

}

void QAQ() {
    int B = sqrt(1e5);
    int n, k;
    cin >> n >> k;

    vector adj(n + 1, vector<int>());

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }

    if (k * B <= 1e5) {
        vector dp(n + 1, vector<int>(k + 1));
        vector<int> sz(n + 1, 1);

        auto dfs = [&](auto & dfs, int u, int fa) -> void {
            dp[u][1] = 1;
            if (k == 1) {
                dp[u][0] = 1;
            }
            for (auto & v : adj[u]) {
                if (v == fa) continue;
                dfs(dfs, v, u);
                sz[u] += sz[v];
                vector<int> dpn(k + 1);

                for (int j = 0; j <= k && j <= sz[u] - sz[v]; j++) {
                    for (int o = 0; o <= k && o <= sz[v]; o++) {
                        if (o + j > k + 1) {
                            continue;
                        }
                        if (!j) {
                            if (!o) {
                                (dpn[0] += dp[u][j] * dp[v][o]) %= mod;
                            } else {
                                continue;
                            }
                        } else {
                            if (j + o == k + 1) {
                                (dpn[0] += dp[u][j] * dp[v][o]) %= mod;
                            } else if (j + o == k) {
                                (dpn[j + o] += dp[u][j] * dp[v][o]) %= mod;
                                if (o) {
                                    (dpn[0] += dp[u][j] * dp[v][o]) %= mod;
                                }
                            } else {
                                (dpn[j + o] += dp[u][j] * dp[v][o]) %= mod;
                            }
                        }
                    }
                }

                swap(dpn, dp[u]);
            }
        };

        dfs(dfs, 1, 0);

        cout << dp[1][0] << "\n";
    } else {
        vector dp(n + 1, vector<int>(B + 1));
        vector<int> sz(n + 1, 1);

        auto dfs = [&](auto & dfs, int u, int fa) -> void {
            dp[u][0] = 1;
            for (auto & v : adj[u]) {
                if (v == fa) continue;
                dfs(dfs, v, u);
                sz[u] += sz[v];
                vector<int> dpn(B + 1);

                for (int j = 0; j <= B && j * k <= sz[u] - sz[v]; j++) {
                    int tj = (sz[u] - sz[v] - j * k) % (k + 1);
                    for (int o = 0; o <= B && o * k <= sz[v]; o++) {
                        int to = (sz[v] - o * k) % (k + 1);
                        if (tj + to > k + 1 || j + o > B) {
                            continue;
                        }
                        if (!tj) {
                            if (!to) {
                                (dpn[j + o] += dp[u][j] * dp[v][o]) %= mod;
                            } else {
                                continue;
                            }
                        } else {
                            if (tj + to == k + 1) {
                                (dpn[j + o] += dp[u][j] * dp[v][o]) %= mod;
                            } else if (tj + to == k) {
                                if (j + o + 1 <= B && to) {
                                    (dpn[j + o + 1] += dp[u][j] * dp[v][o]) %= mod;
                                }
                                (dpn[j + o] += dp[u][j] * dp[v][o]) %= mod;
                            } else {
                                (dpn[j + o] += dp[u][j] * dp[v][o]) %= mod;
                            }
                        }
                    }
                }

                swap(dpn, dp[u]);
            }

        };

        dfs(dfs, 1, 0);

        int ans = 0;

        for (int j = 0; j <= B && j * k <= n; j++) {
            int tj = (n - j * k) % (k + 1);
            if (tj == 0) {
                (ans += dp[1][j]) %= mod;
            }
        }

        cout << ans << "\n";
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