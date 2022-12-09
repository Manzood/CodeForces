#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, h;
    scanf("%lld%lld", &n, &h);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld\n", &a[i]);
    }
    vector<vector<int>> dp(n + 1, vector<int>(6, 0));
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + a[i] / 2;
        dp[i][1] = max(dp[i][0] * 2, dp[i - 1][1] + a[i]);
        dp[i][2] = max((dp[i - 1][1] + a[i]) * 2, dp[i - 1][2] + a[i]);
        dp[i][3] = dp[i][0] * 3;
        dp[i][4] = max((dp[i - 1][1] + a[i]) * 3, dp[i - 1][4] + a[i]);
        dp[i][5] = max((dp[i - 1][2] + a[i]) * 3, dp[i - 1][5] + a[i]);
    }
    int ans = 0;
    for (int i = 0; i < 6; i++) {
        ans = max(ans, dp[n][i]);
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
