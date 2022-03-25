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
    // int ans = 0;
    // if (n & 1) ans = 2;
    // int mult = 1;
    // while (n % 2 == 0) {
    //     n /= 2;
    //     mult *= 2;
    // }
    // if (n == 1) {
    //     printf("-1\n");
    // } else {
    //     if (ans == 0) printf("%lld\n", mult * 2);
    //     else printf("%lld\n", ans);
    // }
    int ans = -1;
    if (n & 1) ans = 2;
    int val = n;

    while (val % 2 == 0) {
        val /= 2;
    }
    for (int i = 3; i * i <= val && (val > 1e9 || (val * (val + 1)) / 2 > n); i += 2) {
        while (val % i == 0) {
            val = val/i;
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
