#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int l, r;
    scanf("%lld%lld", &l, &r);
    int ans = 0;
    for (int i = 0; i <= 60; i++) {
        // [low, hi)
        int low = (1LL << i);
        int hi = (1LL << (i + 1));
        if (low > r || hi <= l) continue;
        int cnt = 1;
        int val = i;
        int x = max(low, l), y = min(hi - 1, r);
        while (x / val >= i) {
            cnt++;
            val *= i;
        }
        while (y / val >= i) {
            (ans += (cnt * ((val * i - max(val, x)) % MOD) % MOD)) %= MOD;
            cnt++;
            val *= i;
        }
        (ans += (cnt * ((y - max(val, x) + 1) % MOD) % MOD)) %= MOD;
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
