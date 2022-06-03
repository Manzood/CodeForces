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
    vector <int> a(n);
    int even = 0, odd = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] & 1) odd++;
        else even++;
    }
    int mi = (int) 1e9 + 7;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        while ((a[i] & 1) == 0) {
            a[i] /= 2;
            cur++;
        }
        mi = min(mi, cur);
    }
    int ans = 0;
    if (!odd) {
        ans = mi;
        even--;
    }
    ans += even;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
