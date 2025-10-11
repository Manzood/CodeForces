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
    vector<int> a(n);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (i & 1) {
            ans -= a[i];
        } else {
            ans += a[i];
        }
    }

    int original = ans;
    if (n > 1) ans = max(ans, original - 2 * a[0] + 2 * a[1] + 1);

    int i1 = 0, i2 = 1;
    for (int i = 2; i < n; i++) {
        if (i % 2 == 0) {
            // i2
            int cost = original;
            cost += 2 * a[i2];
            cost -= 2 * a[i];
            cost += i - i2;

            ans = max(ans, cost);
            ans = max(ans, original + i);

            if (-2 * a[i1] - i1 < -2 * a[i] - i) {
                i1 = i;
            }
        } else {
            int cost = original;
            cost -= 2 * a[i1];
            cost += 2 * a[i];
            cost += i - i1;

            ans = max(ans, cost);
            ans = max(ans, original + i - 1);

            if (2 * a[i2] - i2 < 2 * a[i] - i) {
                i2 = i;
            }
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
