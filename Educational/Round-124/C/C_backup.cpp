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
    int aind = -1, bind = -1, cind = -1, dind = -1;
    for (int i = 0; i < n; i++) {
        if (abs(a[0] - b[i]) < aval) aind = i;
        aval = min(aval, abs(a[0] - b[i]));
        if (abs(b[0] - a[i]) < bval) bind = i;
        bval = min(bval, abs(b[0] - a[i]));
        if (abs(a[n-1] - b[i]) < cval) cind = i;
        cval = min(cval, abs(a[n-1] - b[i]));
        if (abs(b[n-1] - a[i]) < dval) dind = i;
        dval = min(dval, abs(b[n-1] - a[i]));
    }
    int val = aval + cval;
    if (!(bind == 0 && aind == 0) && !(bind == n - 1 && cind == 0)) val += bval;
    if (!(cind == n - 1 && dind == n - 1) && !(dind == 0 && aind == n - 1)) val += dval;
    ans = min(ans, val);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
