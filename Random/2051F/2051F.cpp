#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m, q;
    scanf("%lld%lld%lld", &n, &m, &q);
    m--;
    int st = -1, fin = n, l = m, r = m;
    for (int query = 1; query <= q; query++) {
        int ind;
        scanf("%lld", &ind);
        ind--;

        if (ind <= st) {
            fin--;
        } else if (ind >= fin) {
            st++;
        }

        int pfin = fin;
        if (ind < fin && ind > st && fin < n) fin--;
        if (ind > st && ind < pfin && st > -1) st++;

        if (ind >= l && ind <= r) {
            if (st < 0) st++;
            if (fin == n) fin--;
            if (l == r) {
                l = n;
                r = -1;
            }
        } else if (ind < l && ind < r) {
            l--;
        } else if (ind > l && ind > r) {
            r++;
        }

        // if (test == 1) debug(query, st, fin, l, r);

        int ans = st + 1;
        ans += max(0LL, r - max(st + 1, l) + 1);
        ans += n - max(fin, max(st + 1, r + 1));

        printf("%lld ", ans);
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
