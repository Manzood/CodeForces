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
    int ans = 1;
    int num = 1;
    int mult = 1;
    while (num <= n) {
        if (num == 9 * mult) {
            num = 1 * mult;
            num *= 10;
            mult *= 10;
        } else {
            num += mult;
        }
        if (num <= n) ans++;
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
