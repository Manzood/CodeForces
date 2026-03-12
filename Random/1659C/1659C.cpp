#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, a, b;
    scanf("%lld%lld%lld", &n, &a, &b);
    vector<int> suff(n + 1), x(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x[i]);
    }

    // suff[i] -> how much it takes to conquer everything after position i
    for (int i = n - 1; i >= 0; i--) {
        int diff = i > 0 ? x[i] - x[i - 1] : x[i];
        suff[i] = suff[i + 1] + diff * (n - i);
    }
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
        int diff = i > 0 ? x[i] - x[i - 1] : x[i];
        pref[i + 1] = pref[i] + diff;
    }

    int ans = (int)1e18;
    for (int i = 0; i <= n; i++) {
        int cost = b * suff[i] + pref[i] * (a + b);
        ans = min(ans, cost);
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
