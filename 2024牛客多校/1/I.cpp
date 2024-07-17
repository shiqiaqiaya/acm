#include<bits/stdc++.h>
using namespace std;
#define int long long

void QAQ() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = " " + a[i];
    }

    vector dp(n + 2, vector<array<int, 4>>(m + 2, {-1, -1, -1, -1})), vis(n + 2, vector<array<int, 4>>(m + 2));
    vector mis(n + 1, vector<int>(m + 1));
    vector<array<int, 4>> D = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    auto get = [&](int z, char c) {
        switch (c) {
            case '|' : {
                return (z & 1) ? (z ^ 2) : z;
            } case '-' : {
                return (z & 1) ? z : (z ^ 2);
            } case '/' : {
                return z ^ 1;
            } default : {
                return z ^ 3;
            }
        }
    };

    auto dfs = [&](auto & dfs, int x, int y, int z, int now = 0) -> int {
        if (vis[x][y][z]) {
            return now;
        }
        int nx = x + D[z][0], ny = y + D[z][1];
        if (nx <= 0 || ny <= 0 || nx > n || ny > m) {
            return -1;
        }
        int nz = get(z, a[nx][ny]);

        vis[x][y][z] = 1;
        now += (z != nz) && !mis[nx][ny];
        mis[nx][ny] += z != nz;
        int t = dfs(dfs, nx, ny, nz, now);
        mis[nx][ny] -= z != nz;
        now -= (z != nz) && !mis[nx][ny];
        vis[x][y][z] = 0;

        if (t == -1) {
            dp[nx][ny][z ^ 2] = now;
        } else {
            dp[x][y][z] = t;
        }
        return t;
    };

    for (int i = 1; i <= n; i++) {
        dfs(dfs, i, 0, 1), dfs(dfs, i, m + 1, 3);
    }
    for (int j = 1; j <= m; j++) {
        dfs(dfs, 0, j, 2), dfs(dfs, n + 1, j, 0);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (auto z : {0, 1, 2, 3}) {
                if (dp[i][j][z] == -1) {
                    dfs(dfs, i, j, z);
                }
            }
        }
    }

    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int u, v, z;
        string dir;
        cin >> u >> v >> dir;
        switch (dir[0]) {
            case 'a' : {
                z = 0;
                break;
            } case 'b' : {
                z = 2;
                break;
            } case 'l' : {
                z = 3;
                break;
            } case 'r' : {
                z = 1;
                break;
            }
        }
        cout << dp[u][v][z] << "\n";
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;

    while (t--) {
        QAQ();
    }
}