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

    int ans = 0, len = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            len++;
        } else {
            ans += (len / (k + 1));
            len %= (k + 1);
            if (len == k) ans++;
            len = 0;
        }
    }
    ans += (len / (k + 1));
    len %= (k + 1);
    if (len == k) ans++;

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
