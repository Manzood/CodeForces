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
    int smallest = 0;
    while (((1LL << smallest) & n) == 0) smallest++;
    int cnt = 0;
    for (int i = 0; i <= 30; i++) {
        if ((1LL << i) & n) cnt++;
    }
    int ans = 0;
    if (smallest == 0) {
        if (n == 1) ans = 3;
        else ans = 1;
    } else {
        if (cnt == 1) ans = n + 1;
        else ans = (1LL << smallest);
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
