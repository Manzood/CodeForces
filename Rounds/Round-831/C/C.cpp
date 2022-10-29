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
    sort(a.begin(), a.end());
    // int ans = a.back() - a.front();
    // ans += max(a[1] - a[0], a[n - 1] - a[n - 2]);
    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
        int cur = a[n - 1] - a[i];
        cur += a[i + 1] - a[i];
        ans = max(ans, cur);
    }
    for (int i = n - 1; i >= 2; i--) {
        int cur = a[i] - a[0];
        cur += a[i] - a[i - 1];
        ans = max(ans, cur);
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
