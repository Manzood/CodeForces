#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int k, lx, rx, ly, ry;
    scanf("%lld%lld%lld%lld%lld", &k, &lx, &rx, &ly, &ry);
    int val = 1;
    int ans = 0;
    while (val <= ry) {
        int hi = ry / val;
        int low = ly / val;
        if (ly % val != 0) {
            low++;
        }
        low = max(low, lx);
        hi = min(hi, rx);
        if (test == 3) debug(low, hi);
        ans += abs(hi - low + 1);
        val *= k;
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
