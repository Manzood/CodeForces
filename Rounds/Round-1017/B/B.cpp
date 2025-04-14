#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m, l, r;
    scanf("%lld%lld%lld%lld", &n, &m, &l, &r);
    int rem = n - m;
    int val = min(r, rem);
    rem -= val;
    r -= val;
    l += rem;
    printf("%lld %lld\n", l, r);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
