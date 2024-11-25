#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MX = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(3, {MX, -1}));
    dp[0][0] = {1, 0}, dp[0][1] = {1, a[0] - 1};
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (j + dp[j][1].second - 1 >= i - a[i]) {
                dp[i][0].first = min(dp[i][0].first, dp[j][1].first + 1);
                dp[i][0].second = max(i, dp[j][1].second);
            }
            if (i - a[i] + 1 <= j) {
                dp[i][0].first = min(
                    {dp[i][0].first, dp[j][0].first + 1, dp[j][2].first + 1});
                if (dp[j][0].first < dp[j][2].first) {
                    dp[i][0].first = dp[j][0].first + 1;
                    dp[i][0].second = max(i, dp[j][0].second);
                } else if (dp[j][2].first < dp[j][0].first) {
                    dp[i][0].first = dp[j][2].first + 1;
                    dp[i][0].second = max(i, dp[j][0].second);
                } else {
                    dp[i][0].first = dp[j][0].first + 1;
                    dp[i][0].second =
                        max({i, dp[j][0].second, dp[j][2].second});
                }
            }
            if (i - a[i] + 1 <= 0) {
                dp[i][0].first = 1;
                dp[i][0].second = i;
            }
            if (j + dp[j][1].second >= i) {
                dp[i][1].first = min(dp[i][1].first, dp[j][1].first + 1);
                dp[i][1].second = max(dp[i][1].second, dp[j][1].second);
            }
            dp[i][1].first = min({dp[i][1].first, dp[i - 1][0].first + 1,
                                  dp[i - 1][2].first + 1});  // TODO
            if (j + dp[j][1].second - 1 >= i) {
                dp[i][2].first = min(dp[i][2].first, dp[j][1].first);
                dp[i][2].second = max(dp[i][2].second, dp[j][1].second);
            }
        }
    }
    int ans = min({dp[n - 1][0].first, dp[n - 1][1].first, dp[n - 1][2].first});
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
