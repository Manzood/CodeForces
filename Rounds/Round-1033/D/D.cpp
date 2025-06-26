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
    int a, b, k;
    scanf("%lld%lld%lld", &a, &b, &k);

    int n = k * (a - 1) + 1;

    int val = 1;
    for (int i = n; i >= n - a + 1; i--) {
        (val *= (i % mod)) %= mod;
    }
    int other = 1;
    for (int i = 2; i <= a; i++) {
        (other *= i) %= mod;
    }
    val = (val * inv(other, mod)) % mod;

    (val *= k) %= mod;
    (val *= (b - 1)) %= mod;

    val++;
    val %= mod;
    printf("%lld %lld\n", n % mod, val);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
