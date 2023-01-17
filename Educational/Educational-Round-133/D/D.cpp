#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = 998244353;

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<int> dp(n + 1), ans(n + 1);
    dp[0] = 1;
    for (int s = 0; s + k <= n; s += k++) {
        vector<int> sum(k);
        for (int i = 0; i <= n; i++) {
            int tmp = sum[i % k];
            (sum[i % k] += dp[i]) %= MOD;
            (dp[i] = tmp) %= MOD;
            (ans[i] += dp[i]) %= MOD;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
