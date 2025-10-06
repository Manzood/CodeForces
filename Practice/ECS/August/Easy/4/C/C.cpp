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
    vector<int> l(n, 1), r(n, 1);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) l[i] += l[i - 1];
        ans = max(ans, l[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1]) r[i] += r[i + 1];
    }

    for (int i = 0; i < n; i++) {
        int p = i > 0 ? a[i - 1] : -1;
        int nxt = i < n - 1 ? a[i + 1] : -1;
        int lval = i > 0 ? l[i - 1] : 0;
        int rval = i < n - 1 ? r[i + 1] : 0;
        if (p < nxt) ans = max(ans, lval + rval);
    }

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
