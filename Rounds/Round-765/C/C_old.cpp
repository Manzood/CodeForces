#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(x) 42;
#endif

using namespace std;
#define int long long
const int inf = 1e18;

void solve() {
    int n, l, k;
    scanf("%lld%lld%lld", &n, &l, &k);
    vector<int> pos(n);
    vector<int> value(n);
    vector<int> influence(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &pos[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &value[i]);
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans += (pos[i] - pos[i - 1]) * value[i - 1];
    }
    for (int i = 0; i < n - 1; i++) {
        influence[i] = pos[i + 1] - pos[i];
    }

    influence[n - 1] = l - pos[n - 1];
    ans += value[n - 1] * influence[n - 1];
    vector<vector<int>> dp(n, vector<int>(k + 1, ans));
    vector<vector<int>> cur(n, vector<int>(k + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            cur[i][j] = value[i];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            // dp[i][j] = minimum out of deleting j points until index i
            // cur[i][j] = current value of stop sign i after deleting j points
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            int val = (value[i] - cur[i - 1][j - 1]) * influence[i];
            if (dp[i - 1][j - 1] - val < dp[i][j]) {
                cur[i][j] = cur[i - 1][j - 1];
                dp[i][j] = dp[i - 1][j - 1] - val;
            }
            if (dp[i][j - 1] < dp[i][j]) {
                dp[i][j] = dp[i][j - 1];
                cur[i][j] = cur[i][j - 1];
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= k; j++) {
    //         printf("%lld ", cur[i][j]);
    //     }
    //     printf("\n");
    // }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= k; j++) {
    //         printf("%lld ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    for (int j = 0; j <= k; j++) {
        ans = min(ans, dp[n - 1][j]);
    }
    // debug (dp);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
