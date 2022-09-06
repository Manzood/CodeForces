#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int MAX_N = 1002;

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<int> h(n), w(n);
    vector<vector<int>> dp(MAX_N, vector<int>(MAX_N, 0));
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &h[i], &w[i]);
        dp[h[i]][w[i]] += h[i] * w[i];
    }
    for (int i = 1; i < MAX_N - 1; i++) {
        for (int j = 1; j < MAX_N - 1; j++) {
            dp[i][j] += dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
        }
    }
    for (int i = 0; i < q; i++) {
        int hs, ws, hb, wb;
        scanf("%lld%lld%lld%lld", &hs, &ws, &hb, &wb);
        int ans =
            dp[hb - 1][wb - 1] - dp[hb - 1][ws] - dp[hs][wb - 1] + dp[hs][ws];
        printf("%lld\n", ans);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
