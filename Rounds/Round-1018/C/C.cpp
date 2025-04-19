#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e18;

bool compare_row(vector<vector<int>>& a, int f, int s, int add1, int add2) {
    int n = (int)a.size();
    for (int i = 0; i < n; i++) {
        if (a[f][i] + add1 == a[s][i] + add2) return false;
    }
    return true;
}

bool compare_col(vector<vector<int>>& a, int f, int s, int add1, int add2) {
    int n = (int)a.size();
    for (int i = 0; i < n; i++) {
        if (a[i][f] + add1 == a[i][s] + add2) return false;
    }
    return true;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &y[i]);
    }

    vector<vector<int>> dp(n, vector<int>(2, INF));
    dp[0][0] = 0, dp[0][1] = x[0];
    for (int i = 1; i < n; i++) {
        if (compare_row(a, i - 1, i, 0, 0)) {
            dp[i][0] = dp[i - 1][0];
        }
        if (compare_row(a, i - 1, i, 1, 0)) {
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        }
        if (compare_row(a, i - 1, i, 0, 1)) {
            dp[i][1] = dp[i - 1][0] + x[i];
        }
        if (compare_row(a, i - 1, i, 1, 1)) {
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + x[i]);
        }
    }
    int ans = min(dp[n - 1][0], dp[n - 1][1]);

    dp = vector<vector<int>>(n, vector<int>(2, INF));
    dp[0][0] = 0, dp[0][1] = y[0];
    for (int i = 1; i < n; i++) {
        if (compare_col(a, i - 1, i, 0, 0)) {
            dp[i][0] = dp[i - 1][0];
        }
        if (compare_col(a, i - 1, i, 1, 0)) {
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        }
        if (compare_col(a, i - 1, i, 0, 1)) {
            dp[i][1] = dp[i - 1][0] + y[i];
        }
        if (compare_col(a, i - 1, i, 1, 1)) {
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + y[i]);
        }
    }
    if (ans < INF) ans += min(dp[n - 1][0], dp[n - 1][1]);
    if (ans >= INF) ans = -1;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
