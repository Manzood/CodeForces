#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int N = 26, MX = (int)5e5 + 7, MOD = 998244353;
vector<int> fact(MX, 1);

void precompute() {
    for (int i = 2; i < MX; i++) {
        fact[i] = (i * fact[i - 1]) % MOD;
    }
}

template <typename T>
T getpow(T a, T b, T m) {
    T result = 1;
    while (b) {
        if (b % 2 == 1) result = result * a % m;
        a = a * a % m;
        b /= 2;
    }
    return result;
}

long long inv(long long a, long long m) {
    return 1 < a ? m - inv(m % a, a) * m / a : 1;
}

void solve([[maybe_unused]] int test) {
    vector<int> a(N, 0);
    int len = 0;
    for (int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
        len += a[i];
    }
    vector<vector<vector<int>>> dp(
        N, vector<vector<int>>(len + 5, vector<int>(2, 0)));
    for (int i = 0; i < N; i++) {
        dp[i][0][0] = 1;
        dp[i][0][1] = 1;
    }
    for (int i = 0; i < N; i++) {
        if (a[i] == 0) continue;
        for (int j = a[i]; j < len; j++) {
            int prev = j - a[i];
            dp[i][j][0] += dp[i - 1][j - a[i]][0] *
                           getpow(j - a[i], a[i], MOD) * inv(fact[a[i]], MOD);
            dp[i][j][1] += dp[i - 1][j - a[i]][1] *
                           getpow(j - a[i], a[i], MOD) * inv(fact[a[i]], MOD);
        }
    }
    int cntOdd = len / 2 + (len & 1);
    printf("%lld\n", dp[25][cntOdd][0] * dp[25][len / 2][1]);
}

int32_t main() {
    int t = 1;
    cin >> t;
    precompute();
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
