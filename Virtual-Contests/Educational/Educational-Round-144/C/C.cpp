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
    int l, r;
    scanf("%lld%lld", &l, &r);
    int cnt = 0;
    int val;
    for (int i = l; i <= r; i *= 2) {
        val = i;
        cnt++;
    }
    int ans = 1;
    if (val / 2 * 3 <= r) {
        ans += cnt - 1;
        ans %= MOD;
    }
    int rem = r - val;
    int mult = (1LL << (cnt - 1));
    ans += rem / mult;
    ans %= MOD;
    int v2 = val / 2 * 3;
    rem = r - v2;
    if (rem > 0) {
        mult = (1LL << (cnt - 2));
        mult *= 3;
        ans += rem / mult * (cnt - 1);
        ans %= MOD;
    }
    printf("%lld %lld\n", cnt, ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
