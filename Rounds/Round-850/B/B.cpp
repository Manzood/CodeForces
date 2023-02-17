#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, w, h;
    scanf("%lld%lld%lld", &n, &w, &h);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }
    bool ans = true;
    int mx = -(int)1e18, mi = (int)1e18;
    for (int i = 0; i < n; i++) {
        mx = max(mx, b[i] - a[i]);
        mi = min(mi, b[i] - a[i]);
    }
    if (mx - mi > 2 * (w - h)) ans = false;
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
