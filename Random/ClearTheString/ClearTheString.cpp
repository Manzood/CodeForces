#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int inf = (int)1000;

vector<vector<int>> dp;
int getans(int i, int j, string& s) {
    if (i > j) return 0;
    if (i == j) return dp[i][j] = 1;
    if (dp[i][j] < inf) return dp[i][j];
    for (int k = i + 1; k <= j; k++) {
        int val = s[i] != s[k];
        dp[i][j] =
            min(dp[i][j], getans(i, k - 1, s) + val + getans(k + 1, j, s));
        dp[i][j] =
            min(dp[i][j], getans(i + 1, k, s) + val + getans(k + 1, j, s));
    }
    return dp[i][j];
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    string s;
    cin >> s;
    // dp[i][j] = minimum number of operations to clear s[j...i];
    dp.assign(n, vector<int>(n, inf));
    int ans = getans(0, n - 1, s);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
