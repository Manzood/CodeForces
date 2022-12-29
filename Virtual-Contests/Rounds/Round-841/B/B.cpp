#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int mod = (int)1e9 + 7;
long long inv(long long a, long long m) {
    return 1 < a ? m - inv(m % a, a) * m / a : 1;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    int ans = (((n * (n + 1)) % mod) * (2 * n + 1)) % mod;
    ans = ((ans * inv(6, mod) % mod) * 2) % mod;
    ans -= (n * (n + 1)) / 2;
    ans %= mod;
    if (ans < 0) ans += mod;
    ans = (ans * 2022) % mod;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
