#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    int ans = 0;
    if (min(n, m) > 1) ans = (min(n, m) - 1) * 2;
    if (n == 1 && m == 1) ans = 0;
    else if (min(n, m) == 1 && max(n, m) > 2) ans = -1;
    else {
        int rem = max(n, m) - 1 - min(n, m) + 1;
        rem--; ans++;
        ans += 2 * rem;
        if (rem & 1) ans++;
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
