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
    int val = 1;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] == val) val++;
    }
    int ans = 0;
    if (val <= n) {
        ans = (n - val + k) / k;
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
