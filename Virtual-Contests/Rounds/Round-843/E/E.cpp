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
    int add = 0, sub = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            // want to add
            int diff = abs(a[i]) - add;
            if (diff > 0) {
                ans += diff;
                add += diff;
            }
            sub -= a[i];
            add += a[i];
        } else {
            int diff = a[i] - sub;
            if (diff > 0) {
                ans += diff;
                sub += diff;
            }
            add += a[i];
            sub -= a[i];
        }
        // if (test == 2) debug(ans, add, sub);
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
