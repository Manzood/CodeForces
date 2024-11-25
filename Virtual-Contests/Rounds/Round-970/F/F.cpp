#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7;

long long inv(long long a, long long m) {
    return 1 < a ? m - inv(m % a, a) * m / a : 1;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        (sum += a[i]) %= MOD;
    }
    int tot = 0;
    for (int i = 0; i < n; i++) {
        int val = sum - a[i];
        if (val < 0) val += MOD;
        (tot += (a[i] * val) % MOD) %= MOD;
    }
    int div = (n * (n - 1)) % MOD;
    int ans = (tot * inv(div, MOD)) % MOD;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
