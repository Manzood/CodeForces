#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int w, d, h;
    scanf("%lld%lld%lld", &w, &d, &h);
    int a, b, f, g;
    scanf("%lld%lld%lld%lld", &a, &b, &f, &g);
    int ans = h;
    int add = (int)1e9 + 7;
    add = min(add, a + f + abs(b - g));
    add = min(add, w - a + w - f + abs(b - g));
    add = min(add, abs(a - f) + b + g);
    add = min(add, abs(a - f) + d - b + d - g);
    ans += add;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
