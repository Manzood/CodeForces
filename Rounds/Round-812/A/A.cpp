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
    vector<int> x(n), y(n);
    int hix = 0, mix = 0, hiy = 0, miy = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &x[i], &y[i]);
        hix = max(x[i], hix);
        mix = min(x[i], mix);
        hiy = max(y[i], hiy);
        miy = min(y[i], miy);
    }
    int ans = 2 * abs(hix) + 2 * abs(hiy);
    if (mix < 0) ans += 2 * abs(mix);
    if (miy < 0) ans += 2 * abs(miy);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
