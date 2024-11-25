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
    vector<int> a(n), pref(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        pref[i] = a[i];
        if (i > 0) pref[i] += pref[i - 1];
    }
    map<int, int> latest;
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        if (i > 0) dp[i] = dp[i - 1];
        if (pref[i] == 0) dp[i] = max(dp[i], 1LL);
        if (latest.count(pref[i])) {
            int ind = latest[pref[i]];
            dp[i] = max(dp[i], dp[ind] + 1);
        }
        latest[pref[i]] = i;
    }
    printf("%lld\n", dp[n - 1]);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
