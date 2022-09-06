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
    int a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    n--;
    int ans = 0;
    if (n) {
        ans += min(a, b);
        n--;
    }
    while (n) {
        ans += min({a, b, c});
        n--;
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
