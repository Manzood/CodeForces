#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort (a.rbegin(), a.rend());
    for (int i = 1; i < n; i++) {
        a[i] += a[i-1];
    }
    for (int i = 0; i < q; i++) {
        int x;
        scanf("%lld", &x);
        int ans = lower_bound(a.begin(), a.end(), x) - a.begin();
        printf("%lld\n", ans == n ? -1 : ans + 1);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
