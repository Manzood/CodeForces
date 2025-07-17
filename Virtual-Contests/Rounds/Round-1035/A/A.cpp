#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int a, b, x, y;
    scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
    int ans = (b - a) * x;
    int val = 0;
    if (a & 1) {
        if ((b - a) % 2 == 0) {
            val = (b - a) / 2 * (x + y);
        } else {
            val = (b - a) / 2 * (x + y) + x;
        }
    } else {
        if ((b - a) % 2 == 0) {
            val = (b - a) / 2 * (x + y);
        } else {
            val = (b - a) / 2 * (x + y) + y;
        }
    }
    ans = min(ans, val);
    if (b == a - 1 && (a & 1)) ans = y;
    printf("%lld\n", max(ans, -1LL));
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
