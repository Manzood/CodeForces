#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int mod = 998244353;

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] % a[i] != 0) {
            ans = 0;
            break;
        }
        if (a[i] == a[i - 1]) {
            // any multiple of a[i]
            ans *= (m / a[i]) % mod;
            ans %= mod;
        } else {
            // phi(a[i - 1] / a[i])
            int x = a[i - 1] / a[i];
            int res = x;
            for (int p = 2; p * p <= x; p++) {
                if (x % p == 0) {
                    while (x % p == 0) x /= p;
                    res -= res / p;
                }
            }
            if (x > 1) res -= res / (a[i - 1] / a[i]);
            // if (a[i - 1] / a[i] == 1 && a[i] != 1) res = 0;
            // calculated totient function
            if (test == 4) debug(i, res);
            int cnt = (res * (m / a[i - 1])) % mod;
            // repeat for remainder
            int rem = m % a[i - 1];
            x = a[i - 1] / a[i];
            res = rem / a[i];
            for (int p = 2; p * p <= x; p++) {
                if (x % p == 0) {
                    while (x % p == 0) x /= p;
                    res -= (res / p);
                }
            }
            if (x > 1) res -= res / (a[i - 1] / a[i]);
            if (rem == 1 && a[i] != 1) res = 0;
            cnt += res;
            ans *= (cnt % mod);
            ans %= mod;
        }
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
