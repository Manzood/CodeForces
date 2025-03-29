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
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> pref(n, 0), suff(n, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            if (i > 0)
                pref[i] = pref[i - 1] + a[i];
            else
                pref[i] = a[i];
        } else {
            if (i > 0) pref[i] = pref[i - 1];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < 0) {
            if (i < n - 1)
                suff[i] = suff[i + 1] - a[i];
            else
                suff[i] = -a[i];
        } else {
            if (i < n - 1) suff[i] = suff[i + 1];
        }
    }
    int ans = max(suff[0], pref[n - 1]);
    for (int i = 0; i < n - 1; i++) {
        ans = max(ans, suff[i + 1] + pref[i]);
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
