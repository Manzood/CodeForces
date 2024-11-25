#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int m, k, a, b;
    scanf("%lld%lld%lld%lld", &m, &k, &a, &b);
    int cur = min(b * k, m / k * k);
    cur += min(m - cur, a);
    int ans = m - cur;
    ans = min(ans, m - ((m - cur) / k * k));
    if (a >= k - ((m - cur) % k)) ans = min(ans, (m - cur) / k + 1);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
