#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector <int> prev(n + 1, -1);
    vector <int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        if (i > 0) dp[i] = dp[i-1];
        if (prev[a[i]] == -1) {
            prev[a[i]] = i;
        }
        int dist = i - prev[a[i]] - 1;
        int value = dp[prev[a[i]]] + dist;
        if (dp[i] > value) {
            prev[a[i]] = i;
        } else {
            dp[i] = value;
        }
    }
    printf("%lld\n", dp[n-1]);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
