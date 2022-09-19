#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, x, y;
    scanf("%lld%lld%lld", &n, &x, &y);
    if (x < y) swap(x, y);
    if ((x != 0 && y != 0) || (x == 0 && y == 0) || ((n - 1) % x != 0)) {
        printf("-1\n");
        return;
    }
    int cur = x;
    int val = 1;
    bool first = true;
    for (int i = 0; i < n - 1; i++) {
        if (cur == 0) {
            if (first) {
                val += x + 1;
                first = false;
            } else {
                val += x;
            }
            cur = x;
        }
        printf("%lld ", val);
        cur--;
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
