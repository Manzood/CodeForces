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
    int tot = 0;
    for (int i = a; i < b; i++) {
        if (i & 1) {
            tot += x;
        } else {
            tot += y;
        }
    }
    ans = min(ans, tot);
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
