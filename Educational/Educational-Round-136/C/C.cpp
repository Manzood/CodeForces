#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int mod = 998244353;

int binomialCoeff(int n, int k) {
    if (n < 0 || k < 0) return 0;
    int C[n + 1][k + 1];
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }
    return C[n][k];
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    int a = 0, b = 0, draw = 1;
    int turn = 0;
    for (int i = n; i > 0; i -= 2) {
        // number of ways to get card i -> i - 1 C (i / 2)
        // number of ways to get card i and i - 1 -> i - 2 C (i / 2 - 1)
        if (turn == 0) {
            a += binomialCoeff(i - 1, i / 2);
            b += binomialCoeff(i - 2, i / 2 - 2);
        } else {
            b += binomialCoeff(i - 1, i / 2);
            a += binomialCoeff(i - 2, i / 2 - 2);
        }
        a %= mod;
        b %= mod;
        turn ^= 1;
    }
    printf("%lld %lld %lld\n", a, b, draw);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
