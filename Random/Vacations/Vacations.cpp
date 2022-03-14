#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector <vector <int>> dp(n, vector <int> (3, 0));
    for (int i = 0; i < n; i++) {
        if (i > 0) dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
        if (a[i] == 1 || a[i] == 3) {
            if (i > 0) {
                dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + 1;
            } else {
                dp[i][1] = 1;
            }
        }
        if (a[i] == 2 || a[i] == 3) {
            if (i > 0) {
                dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + 1;
            } else {
                dp[i][2] = 1;
            }
        }
    }
    int mx = max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
    printf("%lld\n", n - mx);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
