#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    vector<int> a(n), b(m);
    map<int, int> x, y;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
        x[b[i]]++;
    }
    int cnt = 0, ans = 0;
    for (int i = 0; i < m; i++) {
        y[a[i]]++;
        if (y[a[i]] <= x[a[i]]) cnt++;
    }
    if (cnt >= k) ans++;
    for (int i = m; i < n; i++) {
        y[a[i - m]]--;
        if (y[a[i - m]] < x[a[i - m]]) cnt--;
        y[a[i]]++;
        if (y[a[i]] <= x[a[i]]) cnt++;
        ans += cnt >= k;
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
