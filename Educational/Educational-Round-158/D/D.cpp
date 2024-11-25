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
    vector<int> a(n), left(n), right(n), leftmax(n, 0), rightmax(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    for (int i = 0; i < n; i++) left[i] = a[i] + i;
    for (int i = n - 1; i >= 0; i--) right[i] = a[i] + (n - 1 - i);

    for (int i = n - 1; i >= 0; i--) {
        leftmax[i] = i == n - 1 ? left[i] : max(leftmax[i + 1], left[i]);
    }
    for (int i = 0; i < n; i++) {
        rightmax[i] = i == 0 ? right[i] : max(rightmax[i - 1], right[i]);
    }

    int ans = (int)1e18 + 7;
    for (int i = 0; i < n; i++) {
        int lval = i == 0 ? 0LL : rightmax[i - 1];
        int rval = i == n - 1 ? 0LL : leftmax[i + 1];
        int val = max({lval, rval, a[i]});
        ans = min(ans, val);
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
