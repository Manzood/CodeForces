#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<int> a(n);
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] & 1)
            y1++;
        else
            x1++;
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
        if (b[i] & 1)
            y2++;
        else
            x2++;
    }

    int ans = min(x1, y2) + min(x2, y1);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
