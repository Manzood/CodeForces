#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int inf = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0LL));
    int ans = inf;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (j > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + (int)(a[i - 1] == (i - j)));
            if (dp[i][j] >= k) {
                ans = min(ans, j);
            }
        }
    }
    if (ans == inf) ans = -1;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
