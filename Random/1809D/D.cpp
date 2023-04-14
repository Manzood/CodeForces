#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int mult = (int)1e12 + 1;

void solve([[maybe_unused]] int test) {
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<vector<int>> dp(n + 1, vector<int>(3));
    // dp[i + 1][0] -> consider first i characters and leave them in form ...0
    // dp[i + 1][1] -> consider first i characters and leave them in form ...01
    // dp[i + 1][2] -> consider first i characters and leave them in form ...11
    dp[0][0] = 0;
    dp[0][1] = mult * (int) 5e5;
    dp[0][2] = mult * (int) 5e5;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][1] + mult - 1;
            dp[i + 1][2] = dp[i][2] + mult;
        } else {
            dp[i + 1][0] = dp[i][0] + mult;
            dp[i + 1][1] = min(dp[i][1] + mult, dp[i][0]);
            dp[i + 1][2] = min(dp[i][2], dp[i][1]);
        }
    }
    printf("%lld\n", min({dp[n][0], dp[n][1], dp[n][2]}));
}

int32_t main() {
        int t = 1;
        cin >> t;
        for (int tt = 1; tt <= t; tt++) {
            solve(tt);
        }
}
