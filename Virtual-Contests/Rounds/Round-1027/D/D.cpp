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
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &x[i], &y[i]);
    }

    if (n == 1) {
        printf("%lld\n", 1LL);
        return;
    }

    vector<int> a = x, b = y;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = (a[n - 1] - a[0] + 1) * (b[n - 1] - b[0] + 1);
    for (int i = 0; i < n; i++) {
        int xmult = a[n - 1] - a[0] + 1;
        int ymult = b[n - 1] - b[0] + 1;

        if (x[i] == a[0]) {
            xmult = a[n - 1] - a[1] + 1;
        } else if (x[i] == a[n - 1]) {
            xmult = a[n - 2] - a[0] + 1;
        }

        if (y[i] == b[0]) {
            ymult = b[n - 1] - b[1] + 1;
        } else if (y[i] == b[n - 1]) {
            ymult = b[n - 2] - b[0] + 1;
        }

        if (xmult * ymult < n) {
            ans = min(ans, min((xmult + 1) * ymult, xmult * (ymult + 1)));
        } else {
            ans = min(ans, xmult * ymult);
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
