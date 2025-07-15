#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, l, r, k;
    scanf("%lld%lld%lld%lld", &n, &l, &r, &k);
    if (n & 1) {
        printf("%lld\n", l);
    } else {
        int cur = 1;
        while (cur <= l) {
            cur *= 2;
        }
        if (cur <= r && n > 2) {
            if (k > n - 2) {
                printf("%lld\n", cur);
            } else {
                printf("%lld\n", l);
            }
        } else {
            printf("-1\n");
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
