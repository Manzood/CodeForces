#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int x, y, k;
    scanf("%lld%lld%lld", &x, &y, &k);
    int z = min(x, y);
    printf("%lld %lld %lld %lld\n", 0LL, 0LL, z, z);
    printf("%lld %lld %lld %lld\n", z, 0LL, 0LL, z);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
