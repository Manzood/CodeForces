#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e18;

void coordinate_compression(vector<int>& a) {
    int n = (int)a.size();
    vector<int> d = a;
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());
    for (int i = 0; i < n; ++i) {
        a[i] = (int)(lower_bound(d.begin(), d.end(), a[i]) - d.begin());
    }
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &c[i]);
    }
    coordinate_compression(a);
    vector<vector<int>> dp(n, vector<int>(n + 1, INF));
    // dp[i][j] = cost for index i if all values <= j and they're all sorted
    for (int j = 0; j < n + 1; j++) {
        if (j >= a[0]) {
            dp[0][j] = 0;
        } else {
            dp[0][j] = c[0];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (a[i] < j) {
                dp[i][j] = min(dp[i][j], c[i] + dp[i - 1][j]);
                dp[i][j] = min(dp[i][j], min(dp[i][a[i]], dp[i - 1][a[i]]));
            } else if (a[i] == j) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            } else {
                dp[i][j] = min(dp[i][j], c[i] + dp[i - 1][j]);
            }
        }
    }
    if (test == 4) debug(a, dp);

    printf("%lld\n", dp[n - 1][n]);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
