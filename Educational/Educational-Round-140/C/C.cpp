#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int mod = 998244353;

// dp[i][j] = dp[i][j - 1] * 2 (if there are no conditions)
// dp[i][j] = dp[i][j - 1] * 2 - 1 (if !same)
// dp[i][j] = 1 (if same)
// condition for zero? if it says same after !same

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0LL));
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
