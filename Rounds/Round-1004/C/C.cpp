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
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> dp(n + 1, 3);
    dp[n] = 1;  // TODO check
    vector<int> suff(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        suff[i] = suff[i + 1] ^ a[i];
    }
    map<int, int> mp;
    mp[0] = n;
    for (int i = n - 1; i >= 0; i--) {
        int val = suff[i];
        /* if (test == 2 && i == 1) debug(val, mp[val]); */
        if (mp.count(val)) {
            int ind = mp[val];
            dp[i] = (((3 * dp[ind]) % MOD) + ((2 * dp[ind - 1]) % MOD)) % MOD;
        }
        mp[val] = i;
    }
    /* if (test == 2) debug(dp); */
    printf("%lld\n", dp[0]);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
