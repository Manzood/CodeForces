#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, s;
    scanf("%lld%lld", &n, &s);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int dx, dy, x, y;
        scanf("%lld%lld%lld%lld", &dx, &dy, &x, &y);

        if (dx == 1 && dy == 1) {
            if (s - x == s - y) ans++;
        } else if (dx == 1 && dy == -1) {
            if (s - x == y) ans++;
        } else if (dx == -1 && dy == 1) {
            if (x == s - y) ans++;
        } else {
            if (x == y) ans++;
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
