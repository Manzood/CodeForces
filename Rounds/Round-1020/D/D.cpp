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
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
    }

    vector<int> right(m, -1), left(m, n);
    int cur = m - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] >= b[cur]) {
            right[cur] = i;
            cur--;
        }
        if (cur < 0) break;
    }
    cur = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= b[cur]) {
            left[cur] = i;
            cur++;
        }
        if (cur >= m) break;
    }

    int ans = -1;
    if (left[m - 1] < n) ans = 0;
    for (int i = 0; i < m; i++) {
        int l = i > 0 ? left[i - 1] : -1;
        int r = i < m - 1 ? right[i + 1] : n;
        if (l < r) {
            if (ans == -1)
                ans = b[i];
            else
                ans = min(ans, b[i]);
        }
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
