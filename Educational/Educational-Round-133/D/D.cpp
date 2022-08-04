#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<int> ans(n + 1, 0);
    int sqrt = 1;
    while (sqrt * sqrt <= n) sqrt++;
    for (int i = k; i * i <= n; i++) {
        for (int mult = 1; i * mult <= n; mult++) {
            ans[i * mult]++;
            if (mult > sqrt) ans[i * mult]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
