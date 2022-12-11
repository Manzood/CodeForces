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
    vector<pair<int, int>> a(m);
    vector<int> f(n, 0);
    for (int i = 0; i < m; i++) {
        scanf("%lld%lld", &a[i].first, &a[i].second);
        a[i].first--;
        a[i].second--;
        if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
        f[a[i].second] = max(a[i].first + 1, f[a[i].second]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0) f[i] = max(f[i], f[i - 1]);
        ans += i - f[i] + 1;
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
