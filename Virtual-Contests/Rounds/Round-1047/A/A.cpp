#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int k, x;
    scanf("%lld%lld", &k, &x);
    for (int i = 0; i < k; i++) {
        x *= 2;
    }
    printf("%lld\n", x);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
