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
    vector<int> a(n), b(n);
    vector<int> apos(n + 1, -1), bpos(n + 1, -1);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        apos[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        bpos[b[i]] = i;
    }
    int ans = 1;
    int f = apos[1];
    int s = bpos[1];
    if (f > s) swap(f, s);
    ans += f * (f + 1) / 2;
    ans += max(0LL, s - f - 1) * max(0LL, s - f) / 2;
    ans += (n - 1 - s) * (n - s) / 2;
    int l = f, r = s;
    for (int nxt = 2; nxt <= n; nxt++) {
        f = apos[nxt];
        s = bpos[nxt];
        if (f > s) swap(f, s);
        if (f < l && s > r) {
            int lval = l - f;
            int rval = s - r;
            ans += lval * rval;
        } else if (s < l) {
            int lval = l - s;
            int rval = n - r;
            ans += lval * rval;
        } else if (f > r) {
            int lval = l + 1;
            int rval = (f - r);
            ans += lval * rval;
        }
        l = min(l, f);
        r = max(r, s);
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
