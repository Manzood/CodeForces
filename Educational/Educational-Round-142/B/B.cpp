#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int alice = 0, bob = 0;
    vector<int> a(4);
    for (int i = 0; i < 4; i++) {
        scanf("%lld", &a[i]);
    }
    int ans = 0;
    ans += a[0];
    alice += a[0];
    bob += a[0];
    if (a[1] > a[2]) swap(a[1], a[2]);
    if (alice > 0) {
        ans += 2 * a[1];
        a[2] -= a[1];
    }
    int rem = min(a[2], bob + 1);
    ans += rem;
    if (rem <= bob) {
        alice += rem;
        bob -= rem;
        rem = min({a[3], bob + 1, alice + 1});
        ans += rem;
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
