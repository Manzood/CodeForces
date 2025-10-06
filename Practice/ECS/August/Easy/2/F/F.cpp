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
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%lld%lld", &x, &y);
        a[i] = {y - x, x, y};
    }

    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i][1] * i + a[i][2] * (n - i - 1);
    }

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
