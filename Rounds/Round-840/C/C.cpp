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
    if (n > 3) {
        ans = *max_element(a.begin(), a.end()) * n;
    } else {
        if (n == 2) {
            ans = max(a[0] + a[1], 2 * abs(a[1] - a[0]));
        } else {
            // double check this
            ans = a[0] * 3;
            ans = max(ans, a[2] * 3);
            ans = max(ans, a[0] + a[1] + a[2]);
            ans = max(ans, a[0] + 2 * abs(a[2] - a[1]));
            ans = max(ans, a[2] + 2 * abs(a[0] - a[1]));
            ans = max(ans, 2 * abs(a[2] - abs(a[0] - a[1])) + abs(a[0] - a[1]));
            ans = max(ans, 2 * abs(a[0] - abs(a[2] - a[1])) + abs(a[2] - a[1]));
            ans = max(ans, 3 * abs(a[1] - a[0]));
            ans = max(ans, 3 * abs(a[2] - a[1]));
            ans = max(ans, 3 * abs(a[0] - a[2]));
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
