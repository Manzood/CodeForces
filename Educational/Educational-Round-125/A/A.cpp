#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int x, y;
    scanf("%lld%lld", &x, &y);
    int temp = 1;
    int val = x * x + y * y;
    while (temp * temp < val) {
        temp++;
    }
    int ans = 0;
    if (val > 0 && temp * temp == val) {
        ans = 1;
    } else if (val > 0) {
        ans = 2;
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
