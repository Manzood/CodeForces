#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7;

constexpr int MX = 64;

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<vector<int>> dp(n, vector<int>(MX, 0));
    dp[0][a[0]]++;
    for (int i = 1; i < n; i++) {
        dp[i][a[i]]++;
        for (int j = 0; j < MX; j++) {
            (dp[i][j] += dp[i - 1][j]) %= MOD;
            (dp[i][a[i] & j] += dp[i - 1][j]) %= MOD;
        }
    }
    int ans = 0;
    for (int j = 0; j < MX; j++) {
        if (__builtin_popcountll(j) == k) (ans += dp[n - 1][j]) %= MOD;
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
