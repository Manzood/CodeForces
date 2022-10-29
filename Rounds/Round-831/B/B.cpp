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
    int sum = 0, other = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i], &b[i]);
        sum += min(a[i], b[i]);
        other = max(other, max(a[i], b[i]));
    }
    int ans = 2 * (sum + other);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
