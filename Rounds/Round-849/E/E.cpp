#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e18;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<vector<int>> dp(n, vector<int>(2, -INF));
    dp[0][0] = a[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0] + a[i], dp[i - 1][1] + a[i]);
        dp[i][1] = max(dp[i - 1][0] - 2 * a[i - 1] - a[i],
                       dp[i - 1][1] + 2 * a[i - 1] - a[i]);
    }
    printf("%lld\n", max(dp[n - 1][0], dp[n - 1][1]));
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
