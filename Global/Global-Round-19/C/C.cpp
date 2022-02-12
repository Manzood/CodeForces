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
    int ans = 0;
    bool possible = false;
    int odd = 0;
    int gt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (i > 0 && i < n - 1) {
            ans += a[i] / 2 + (a[i] & 1);
            if (a[i] & 1) {
                odd++;
            }
            if (a[i] >= 2) {
                gt++;
            }
        }
    }
    if (gt > 0 && n > 3) possible = true;
    if (n == 3 && odd == 1) possible = false;
    if (!possible && odd == 0) possible = true;
    if (possible) {
        printf("%lld\n", ans);
    } else {
        printf("-1\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
