#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int l, r, x, a, b;
    scanf("%lld%lld%lld%lld%lld", &l, &r, &x, &a, &b);
    int ans = 100;
    if (a == b) ans = 0;
    if (abs(a - b) >= x) ans = 1;
    if (abs(l - a) >= x) {
        if (abs(l - b) >= x) ans = min(ans, 2LL);
    } else if (abs(r - a) >= x) {
        if (abs(l - b) >= x) ans = min(ans, 3LL);
    }
    if (abs(r - a) >= x) {
        if (abs(r - b) >= x) ans = min(ans, 2LL);
    } else if (abs(l - a) >= x) {
        if (abs(r - b) >= x) ans = min(ans, 3LL);
    }
    if (ans >= 100) ans = -1;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
