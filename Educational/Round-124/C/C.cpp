#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
const int inf = 1e18;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }
    int ans = abs(a[0] - b[0]) + abs(a[n-1] - b[n-1]);
    ans = min(ans, abs(a[0] - b[n-1]) + abs(a[n-1] - b[0]));

    int aval = inf, bval = inf, cval = inf, dval = inf;
    for (int i = 0; i < n; i++) {
        aval = min(aval, abs(a[0] - b[i]));
        bval = min(bval, abs(b[0] - a[i]));
        cval = min(cval, abs(a[n-1] - b[i]));
        dval = min(dval, abs(b[n-1] - a[i]));
    }

    ans = min(ans, abs(a[0] - b[0]) + cval + dval);
    ans = min(ans, abs(a[0] - b[n-1]) + cval + bval);
    ans = min(ans, abs(a[n-1] - b[0]) + aval + dval);
    ans = min(ans, abs(a[n-1] - b[n-1]) + aval + bval);
    ans = min(ans, aval + bval + cval + dval);

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
