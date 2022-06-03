#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector <int> pref(n, 0);
    for (int i = 0; i < n; i++) {
        if (i > 0) pref[i] += pref[i - 1];
        pref[i] += a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        int p_index = max(0LL, i - k + 1);
        if (p_index > 0) cur = pref[i] - pref[p_index - 1];
        else cur = pref[i];
        ans = max(ans, cur);
    }
    // how many remaining?
    // do laps
    if (k > n) {
        // int laps = k / n;
        // // do full laps
        // ans += laps * max(n * (n - 1), 1LL);
        // int rem = k % n;
        // if (rem) ans += rem * (rem - 1);
        // stay at the first spot until n - 1 remain
        int tot = k - n;
        int cur = tot + 1;
        ans += tot;
        for (int i = 0; i < n - 1; i++) {
            ans += cur + i;
        }
    } else {
        int chosen = min(k, n);
        ans += (chosen * (chosen - 1)) / 2;
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
