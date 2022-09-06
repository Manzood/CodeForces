#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int q, x;
    scanf("%lld%lld", &q, &x);
    vector<int> found(x, 0);
    int mex = 0;
    for (int i = 0; i < q; i++) {
        int y;
        scanf("%lld", &y);
        y %= x;
        found[y]++;
        while (found[mex % x] > mex / x) mex++;
        printf("%lld\n", mex);
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
