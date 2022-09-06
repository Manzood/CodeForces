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
    int mx = 0, mi = 1000;
    // int mx_pos = -1, mi_pos = -1;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        // if (a[i] > mx) mx_pos = i;
        // if (a[i] < mi) mi_pos = i;
        mx = max(a[i], mx);
        mi = min(a[i], mi);
    }
    // int ans = max({mx - a[0], a[n - 1] - mi, a[n - 1] - a[0], a[0] - a[n -
    // 1]});
    int ans = a[n - 1] - a[0];
    for (int i = 0; i < n - 1; i++) {
        ans = max(ans, a[i] - a[i + 1]);
    }
    // ans = max(ans, a[0] - a[n - 1]);
    ans = max({ans, mx - a[0], a[n - 1] - mi});
    // if (mx_pos + 1 < n) ans = max(ans, mx - a[mx_pos + 1]);
    // if (mi_pos - 1 >= 0) ans = max(ans, a[mi_pos - 1] - mi);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
