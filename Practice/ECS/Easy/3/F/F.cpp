#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = 998244353;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }

    for (int i = 0; i < n; i++) {
        a[i] *= (i + 1) * (n - i);
    }

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        a[i] %= MOD;
        (ans += a[i] * b[i] % MOD) %= MOD;
    }

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
