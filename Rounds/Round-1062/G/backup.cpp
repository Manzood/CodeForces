#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e18;

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

    vector<vector<int>> dp(n, vector<int>(2, INF));
    dp[0][0] = 0;
    dp[0][1] = c[0];
    for (int i = 1; i < n; i++) {
        // dp[i][0]
        int val = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] <= a[i]) {
                dp[i][0] = min(dp[i][0], dp[j][0] + val);
                if (test == 6 && i == 4) debug(dp[i][0]);
            } else {
                val += c[j];  // TODO is this enough?
            }
        }
        dp[i][0] = min(dp[i][0], val);

        // dp[i][1]
        dp[i][1] = c[i] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    if (test == 6) debug(dp);

    printf("%lld\n", min(dp[n - 1][0], dp[n - 1][1]));
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
