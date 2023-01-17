#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    debug(dp);
    for (int j = k; j <= n; j++) {
        vector<int> copy = dp;
        dp[0] = 0;
        for (int i = j; i <= n; i += j) {
            dp[i] += dp[i - j];
            dp[i] += copy[i - j];
        }
        dp[0] = 1;
        debug(dp);
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld ", dp[i]);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
