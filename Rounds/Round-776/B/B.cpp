#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int l, r, a;
    scanf("%lld%lld%lld", &l, &r, &a);
    int ans = l / a + l % a;
    ans = max(ans, r / a + r % a);
    int other = r / a;
    other *= a;
    other--;
    if (other >= l) {
        ans = max(ans, other / a + other % a);
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
