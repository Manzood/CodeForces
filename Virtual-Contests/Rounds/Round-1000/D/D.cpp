#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e17 + 7;

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
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> achoose(n + 1, 0), bchoose(m + 1, 0), apref(n + 1, 0),
        bpref(m + 1, 0);
    for (int i = 2; i <= n; i += 2) {
        achoose[i] = a[n - i / 2] - a[i / 2 - 1];
        apref[i] = achoose[i] + apref[i - 2];
    }
    for (int i = 2; i <= m; i += 2) {
        bchoose[i] = b[m - i / 2] - b[i / 2 - 1];
        bpref[i] = bchoose[i] + bpref[i - 2];
    }

    int kmax = 0;
    if (m <= n / 2)
        kmax = m;
    else
        kmax = min(n, (n + m) / 3);
    printf("%lld\n", kmax);

    for (int k = 1; k <= kmax; k++) {
        int low = max(0LL, 2 * k - m), high = min(k, n - k);
        int ans = low;
        while (low < high) {
            int x = (low + high) / 2;
            int cur = apref[x * 2] + bpref[(k - x) * 2];
            int xl =
                x == low ? -INF : apref[(x - 1) * 2] + bpref[(k - (x - 1)) * 2];
            int xr = x == high ? -INF
                               : apref[(x + 1) * 2] + bpref[(k - (x + 1)) * 2];
            if (cur >= xl && cur >= xr) {
                ans = x;
                break;
            } else if (xl <= cur && cur <= xr) {
                low = x + 1;
                ans = low;
            } else {
                high = x - 1;
            }
        }
        printf("%lld ", apref[ans * 2] + bpref[(k - ans) * 2]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
