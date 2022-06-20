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
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int q;
    scanf("%lld", &q);
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%lld", &t);
        int ans = -1;
        for (int j = 1; j <= n; j++) {
            int leftover = 0;
            bool found = true;
            for (int k = 0; k < j; k++) {
                if (a[k] - leftover > t) {
                    found = false;
                }
                leftover += t - a[k];
            }
            for (int k = j; k < n; k++) {
                leftover -= a[k];
                if (leftover < 0) found = false;
            }
            if (found) {
                ans = j;
                break;
            }
        }
        printf("%lld\n", ans);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
