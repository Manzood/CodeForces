#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, b, x, y;
    scanf("%lld%lld%lld%lld", &n, &b, &x, &y);
    int val = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (val + x > b) {
            val -= y;
        } else {
            val += x;
        }
        sum += val;
    }
    printf("%lld\n", sum);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
