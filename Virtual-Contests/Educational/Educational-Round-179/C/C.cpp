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

    int cur = a[0], len = 1;
    int ans = (int)1e17 + 7;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            ans = min(ans, cur * (n - len));
            cur = a[i];
            len = 1;
        } else {
            len++;
        }
    }
    ans = min(ans, cur * (n - len));

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
