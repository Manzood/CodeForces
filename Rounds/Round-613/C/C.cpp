#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int x;
    scanf("%lld", &x);
    int ans = x;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0 && __gcd(i, x / i) == 1) {
            ans = min(ans, x / i);
        }
    }
    printf("%lld %lld\n", x / ans, ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
