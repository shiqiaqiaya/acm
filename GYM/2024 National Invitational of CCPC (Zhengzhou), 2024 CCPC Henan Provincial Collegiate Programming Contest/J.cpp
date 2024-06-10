#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> is_prime, prime;

auto Euler = [](int n) {
    is_prime = vector<int>(n + 1, true), prime = vector<int>();
    is_prime[1] = is_prime[0] = false;  //true为素数
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime.push_back(i);
        }//以下不是素数也需要筛
        for (auto x : prime) {
            if (i * x > n) break;
            is_prime[x * i] = false;
            if (i % x == 0) break;
        }
    }
};

void QWQ() {

}

void QAQ() {
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    do {
        if (s[0] == '0') {
            continue;
        }
        auto t = stoi(s);
        if (!is_prime[t]) {
            cout << t << "\n";
            return;
        }
    } while (next_permutation(s.begin(), s.end()));
    cout << "-1\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    cin >> t;

    Euler(1e5);

    while (t--) {
        QAQ();
    }
}