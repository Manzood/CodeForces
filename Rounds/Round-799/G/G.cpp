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
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector <bool> is_true(n, false);
    is_true[0] = true;
    for (int i = 1; i < n; i++) {
        if (2 * a[i] > a[i-1]) is_true[i] = true;
        else is_true[i] = false;
    }
    int len = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!is_true[i]) {
            len = 1;
        } else {
            len++;
            if (len >= k + 1) {
                ans++;
            }
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
