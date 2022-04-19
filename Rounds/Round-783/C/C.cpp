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
    int ans = (int) 1e18;
    for (int k = 0; k < n; k++) {
        int moves = 0;
        int p_val = 0;
        for (int i = k - 1; i >= 0; i--) {
            int cur = -p_val;
            int mult = cur / a[i] + 1;
            p_val = -(a[i] * mult);
            moves += mult;
        }
        p_val = 0;
        for (int i = k + 1; i < n; i++) {
            int mult = p_val / a[i] + 1;
            p_val = a[i] * mult;
            moves += mult;
        }
        // debug(k, moves);
        ans = min(ans, moves);
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
