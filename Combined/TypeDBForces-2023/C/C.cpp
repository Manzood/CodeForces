#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, s;
    scanf("%lld%lld", &n, &s);
    vector<int> a(n);
    vector<pair<int, int>> choices(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        choices[i].first = min(a[i], s);
        choices[i].second = a[i] - choices[i].first;
    }
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    // dp[i][j] = minimum possible value until index i - 1 picking jth element
    dp[1][0] = a[0] * choices[1].first;
    dp[1][1] = a[0] * choices[1].second;
    for (int i = 2; i < n - 1; i++) {
        dp[i][0] = min(dp[i - 1][0] + choices[i - 1].second * choices[i].first,
                       dp[i - 1][1] + choices[i - 1].first * choices[i].first);
        dp[i][1] = min(dp[i - 1][0] + choices[i - 1].second * choices[i].second,
                       dp[i - 1][1] + choices[i - 1].first * choices[i].second);
    }
    dp[n - 1][0] = dp[n - 2][0] + choices[n - 2].second * a[n - 1];
    dp[n - 1][1] = dp[n - 2][1] + choices[n - 2].first * a[n - 1];
    int ans = min(dp[n - 1][0], dp[n - 1][1]);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}

