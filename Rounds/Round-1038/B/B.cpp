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
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        if (c < a) ans += a - c;
        if (d < b) ans += min(a, c) + b - d;
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
