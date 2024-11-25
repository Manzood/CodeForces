#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int mod = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    // base case assignment
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= i + 1; j++) {
            dp[i][j] += dp[i - 1][j];
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
