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
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    bool prev = false;
    for (int i = 1; i < n; i++) {
        int diff = abs((n - i - 1) - (i - 1));
        if (diff <= k) {
            ans += a[i] - a[i - 1] + 1;
            if (prev) ans--;
            prev = true;
        } else {
            prev = false;
        }
    }
    if (k == 0 && (n & 1)) {
        ans = 1;
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
