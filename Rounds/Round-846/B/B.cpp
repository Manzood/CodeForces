#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    vector<int> pref(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (i > 0)
            pref[i] = pref[i - 1] + a[i];
        else
            pref[i] = a[i];
    }
    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
        ans = max(ans, __gcd(pref[i], pref[n - 1] - pref[i]));
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
