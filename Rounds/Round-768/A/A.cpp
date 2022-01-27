#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }
    int mx = max (a[0], b[0]);
    int mi = min(a[0], b[0]);
    for (int i = 0; i < n; i++) {
        mi = max (mi, min(a[i], b[i]));
        mx = max (mx, a[i]);
        mx = max (mx, b[i]);
    }
    printf("%lld\n", mx * mi);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
