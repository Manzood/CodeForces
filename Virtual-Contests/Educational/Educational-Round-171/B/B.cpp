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
    int ans = 1;
    if (n & 1) {
        ans = (int)1e18 + 7;
        vector<int> left(n, 1), right(n, 1);
        for (int i = 1; i < n; i++) {
            if (i > 1)
                left[i] = max(left[i - 2], a[i] - a[i - 1]);
            else
                left[i] = a[i] - a[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            if (i < n - 2)
                right[i] = max(right[i + 2], a[i + 1] - a[i]);
            else
                right[i] = a[i + 1] - a[i];
        }
        for (int i = 0; i < n; i += 2) {
            int x = 1;
            if (i > 0) x = max(x, left[i - 1]);
            if (i < n - 1) x = max(x, right[i + 1]);
            ans = min(ans, x);
        }
    } else {
        for (int i = 1; i < n; i += 2) {
            ans = max(ans, a[i] - a[i - 1]);
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
