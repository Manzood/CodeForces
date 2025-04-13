#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int x, n, m;
    scanf("%lld%lld%lld", &x, &n, &m);
    // smallest
    n = min(n, 32LL), m = min(m, 32LL);
    int val = x;
    int f = n, s = m;
    for (int i = 0; i < n + m; i++) {
        if (val == 0) break;
        if (s) {
            s--;
            if (val & 1)
                val = val / 2 + 1;
            else
                val /= 2;
        } else {
            val /= 2;
        }
    }
    int mi = val;
    val = x;
    f = n, s = m;
    for (int i = 0; i < n + m; i++) {
        if (val == 0) break;
        if (f) {
            val /= 2;
            f--;
        } else {
            if (val & 1)
                val = val / 2 + 1;
            else
                val /= 2;
        }
    }
    printf("%lld %lld\n", mi, val);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
