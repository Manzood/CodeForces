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
    int n, l, target;
    scanf("%lld%lld%lld", &n, &l, &target);
    vector<int> pos(n);
    vector<int> limit(n);
    vector<int> influence(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &pos[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &limit[i]);
    }
    pos.push_back(l);
    for (int i = 0; i < n; i++) {
        influence[i] = pos[i + 1] - pos[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += limit[i] * influence[i];
    }
    debug (ans);
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(target + 1, vector<int>(target + 1, ans)));

    for (int i = 1; i < n; i++) {
        // keeping sign i
        for (int j = 0; j <= target && j <= i - 1; j++) {
            // removing the previous j positions
            // int cur = limit[i-j-1];
            int lastsign = i - j - 1;
            int rem = target - j;
            for (int k = 0; k + j <= target; k++) {
                debug(i, j, k);
                debug (rem, lastsign);
                if (j == 0) dp[i][j][k] = min (dp[i][j][k], dp[lastsign][rem][k]);
                if (j < target) dp[i][j][k] = min (dp[i][j][k], dp[i-1][j+1][k] - (influence[i-1] * limit[i-1]) + (influence[i-1] * limit[lastsign]));
                ans = min(ans, dp[i][j][k]);
            }
        }
    }

    debug (dp);

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
