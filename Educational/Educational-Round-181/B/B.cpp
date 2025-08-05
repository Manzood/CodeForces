#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int a, b, k;
    scanf("%lld%lld%lld", &a, &b, &k);

    int ans = 2;
    int val = gcd(a, b);
    if (a / val <= k && b / val <= k) {
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
