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
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> f(n, 0), s(n, 0);
    for (int i = 0; i < m; i++) {
        f[a[i] - 1]++;
        s[n - a[i]]++;
    }
    for (int i = 1; i < n; i++) s[i] += s[i - 1];
    for (int i = n - 2; i >= 0; i--) f[i] += f[i + 1];
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += f[i] * s[i + 1];
    }
    for (int i = 0; i < m; i++) {
        int r = a[i] - 1;
        int l = n - a[i];
        int overlap = r < l - 1 ? 0 : r - l + 2;
        ans -= overlap;
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
