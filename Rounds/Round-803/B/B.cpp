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
    int taller = 0;
    for (int i = 1; i < n - 1; i++) {
        if (a[i] > a[i - 1] + a[i + 1]) taller++;
    }
    int ans = 0;
    if (k == 1) {
        ans = n - 2;
        ans /= 2;
        if (n & 1) ans++;
    } else {
        ans = taller;
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
