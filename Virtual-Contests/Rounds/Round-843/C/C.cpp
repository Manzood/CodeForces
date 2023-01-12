#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, x;
    scanf("%lld%lld", &n, &x);
    int init = n;
    bool found = false;
    int moves = 0;
    int res = n;
    for (int j = 0; j < 64 && !found; j++) {
        if ((1LL << j) & x) {
            if (!((1LL << j) & n)) {
                // make it 1
                n += (1LL << j);
                moves += (1LL << j);
            }
            break;
        } else {
            if ((1LL << j) & n) {
                // make it zero
                n += (1LL << j);
                moves += (1LL << j);
            }
        }
        res &= n;
        if (res == x) found = true;
    }
    res &= n;
    if (res == x) found = true;
    if (found) {
        printf("%lld\n", init + moves);
    } else {
        printf("-1\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
