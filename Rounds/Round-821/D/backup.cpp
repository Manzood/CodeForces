#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e2 + 7;

void solve([[maybe_unused]] int test) {
    int n, x, y;
    scanf("%lld%lld%lld", &n, &x, &y);
    string a, b;
    cin >> a >> b;
    vector<vector<int>> dp(n, vector<int>(n, INF));
    vector<vector<int>> cnt(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        // calculate for i - 1;
        if (a[i] == b[i]) dp[i][i] = 0;
        if (i > 0) {
            if (a[i] == b[i]) {
                if (a[i - 1] == b[i - 1])
                    dp[i][i - 1] = 0;
                else
                    cnt[i][i - 1] = 1;
            } else {
                if (a[i - 1] != b[i - 1]) {
                    dp[i][i - 1] = x;
                    cnt[i][i - 1] = 2;
                } else {
                    cnt[i][i - 1] = 1;
                }
            }
        }
        for (int j = i - 2; j >= 0; j--) {
            if (a[i] == b[i]) {
                if (a[j] == b[j]) {
                    dp[i][j] = dp[i - 1][j + 1];
                    cnt[i][j] = cnt[i][j + 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                    cnt[i][j] = cnt[i - 1][j];
                }
            } else {
                if (a[j] == b[j]) {
                    dp[i][j] = dp[i][j + 1];
                    cnt[i][j] = cnt[i][j + 1];
                } else {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + y);
                    cnt[i][j] = cnt[i][j + 1] + 1;
                }
            }
            if (j == i - 3) {
                if (cnt[i][j] == 4) {
                    dp[i][j] = min(dp[i][j], 2 * y);
                } else if (cnt[i][j] == 2) {
                    dp[i][j] = min(dp[i][j], 3 * y);
                    if (cnt[i - 1][i - 2] != 2) {
                        dp[i][j] = min(dp[i][j], 2 * y);
                    }
                }
            }
            if (j <= i - 4) {
                if ((cnt[i][j] & 1) == 0) {
                    dp[i][j] = min(dp[i][j], cnt[i][j] * y);
                }
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     printf("i: %lld :", i);
    //     for (int j = i; j >= 0; j--) {
    //         printf("%lld ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    if (dp[n - 1][0] == INF) dp[n - 1][0] = -1;
    if (cnt[n - 1][0] % 2 == 1) {
        assert(dp[n - 1][0] = -1);
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
