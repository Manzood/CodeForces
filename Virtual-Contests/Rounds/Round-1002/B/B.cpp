#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    if (n == k) {
        int ans = n / 2 + 1;
        for (int i = 1; i < n; i += 2) {
            if (a[i] != i / 2 + 1) {
                ans = i / 2 + 1;
                break;
            }
        }
        printf("%lld\n", ans);
        return;
    }
    bool found = false;
    for (int i = 1; i <= n - k + 1; i++) {
        if (a[i] != 1) found = true;
    }
    int ans = found ? 1LL : 2LL;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
