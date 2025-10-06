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
    vector<int> a(k);
    vector<int> f(n + 1, -1), l(n + 1, -1);

    for (int i = 0; i < k; i++) {
        scanf("%lld", &a[i]);
        if (f[a[i]] == -1) f[a[i]] = i;
        l[a[i]] = i;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            if (f[i] == -1 || f[i - 1] == -1 || f[i] > l[i - 1]) {
                ans++;
            }
        }
        if (f[i] == -1) ans++;
        if (i < n) {
            if (f[i] == -1 || f[i + 1] == -1 || f[i] > l[i + 1]) {
                ans++;
            }
        }
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
