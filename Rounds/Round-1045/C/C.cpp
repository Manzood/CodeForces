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
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    int ans = 0;
    for (int i = 1; i < n; i += 2) {
        int val = 0;
        val += a[i - 1];
        if (i + 1 < n) val += a[i + 1];

        if (val > a[i]) {
            int diff = val - a[i];
            ans += diff;

            if (i + 1 < n) {
                a[i + 1] -= min(a[i + 1], diff);
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
