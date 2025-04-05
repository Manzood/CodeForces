#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = 998244353;

void solve([[maybe_unused]] int test) {
    int n, m, d;
    scanf("%lld%lld%lld", &n, &m, &d);
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> only_up(n, vector<int>(m + 1, 0)),
        dp(n, vector<int>(m + 1, 0));
    for (int i = 0; i < m; i++) {
        if (a[0][i] == 'X') {
            only_up[0][i + 1] = 1;
            dp[0][i + 1] = 1;
        }
        only_up[0][i + 1] += only_up[0][i];
    }
    for (int i = 0; i < m; i++) {
        if (a[0][i] != 'X') continue;
        int left = max(0LL, i - d), right = min(m - 1, i + d);
        dp[0][i + 1] = only_up[0][right + 1] - only_up[0][left];
    }
    for (int i = 0; i < m; i++) {
        (dp[0][i + 1] += dp[0][i]) %= MOD;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 'X') continue;
            int left = max(0LL, j - d + 1), right = min(m - 1, j + d - 1);
            only_up[i][j] =
                (((dp[i - 1][right + 1] - dp[i - 1][left]) % MOD) + MOD) % MOD;
        }
        vector<int> cpy = only_up[i];
        only_up[i][0] = 0;
        for (int j = 0; j < m; j++) {
            (only_up[i][j + 1] = (cpy[j] + only_up[i][j]) % MOD) %= MOD;
        }
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 'X') continue;
            int left = max(0LL, j - d), right = min(m - 1, j + d);
            dp[i][j] =
                (((only_up[i][right + 1] - only_up[i][left]) % MOD) + MOD) %
                MOD;
        }
        cpy = dp[i];
        dp[i][0] = 0;
        for (int j = 0; j < m; j++) {
            (dp[i][j + 1] = (cpy[j] + dp[i][j]) % MOD) %= MOD;
        }
    }
    int ans = dp[n - 1][m];
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
