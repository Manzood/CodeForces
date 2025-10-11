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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    vector<vector<int>> occ(n + 1);
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        occ[a[i - 1]].push_back(i);

        if ((int)occ[a[i - 1]].size() >= a[i - 1]) {
            int val = (int)occ[a[i - 1]].size() - a[i - 1];
            // debug(a[i - 1], occ[a[i - 1]].size(), val);
            int last = occ[a[i - 1]][val];
            dp[i] = max(dp[i], dp[last - 1] + a[i - 1]);
        }
    }

    printf("%lld\n", dp[n]);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
