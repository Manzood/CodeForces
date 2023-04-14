#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int mod = 998244353;

long long inv(long long a, long long m) {
    return 1 < a ? m - inv(m % a, a) * m / a : 1;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int ans = 1;
    for (int i = 0; i < n; i += 3) {
        vector<int> tmp = {a[i], a[i + 1], a[i + 2]};
        sort(tmp.begin(), tmp.end());
        if (tmp[2] == tmp[1] && tmp[1] == tmp[0]) {
            (ans *= 3) %= mod;
        } else if (tmp[1] == tmp[0]) {
            (ans *= 2) %= mod;
        }
    }
    int ncr = 1;
    for (int i = 2; i <= n / 3; i++) (ncr *= i) %= mod;
    int div = 1;
    for (int i = 2; i <= n / 6; i++) (div *= i) %= mod;
    (ncr *= inv(div, mod)) %= mod;
    (ncr *= inv(div, mod)) %= mod;
    (ans *= ncr) %= mod;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
