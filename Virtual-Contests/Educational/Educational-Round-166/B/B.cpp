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
    vector<int> a(n), b(n + 10);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n + 1; i++) {
        scanf("%lld", &b[i]);
    }
    int diff = (int)1e18, ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - b[i]);
        if (b[n] >= min(a[i], b[i]) && b[n] <= max(a[i], b[i])) {
            diff = 0;
        }
        diff = min(diff, abs(a[i] - b[n]));
        diff = min(diff, abs(b[i] - b[n]));
    }
    ans += diff + 1;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
