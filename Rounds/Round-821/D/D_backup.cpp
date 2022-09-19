#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e18 + 7;

void solve([[maybe_unused]] int test) {
    int n, x, y;
    scanf("%lld%lld%lld", &n, &x, &y);
    string a, b;
    cin >> a >> b;
    vector<vector<int>> dp(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            dp[i][i] = 0;
        }
        for (int j = i - 1; j >= 0; j--) {
            if (a[i] == b[i]) {
                if (a[j] == b[j]) {
                    if (j < i - 1) {
                        dp[i][j] = dp[i - 1][j + 1];
                    } else {
                        dp[i][j] = 0;
                    }
                } else {
                    if (j < i - 1) {
                        // leave it alone
                        dp[i][j] = dp[i - 1][j];
                        // flip it
                    }
                    // otherwise INF
                }
            } else {
                if (a[j] == b[j]) {
                    if (j < i - 1) {
                        dp[i][j] = dp[i][j + 1];
                    }
                    if (j < i - 2) {
                        if (dp[i][i - 1] != INF) {
                            dp[i][j] = min(dp[i][j], 2 * y + dp[i - 2][j]);
                        }
                    }
                    // otherwise INF
                } else {
                    if (j < i - 1) {
                        // flip both
                        dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + y);
                    } else {
                        dp[i][j] = min(dp[i][j], x);
                    }
                }
            }
        }
    }
    if (dp[n - 1][0] == INF) {
        dp[n - 1][0] = -1;
    }
    printf("%lld\n", dp[n - 1][0]);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
