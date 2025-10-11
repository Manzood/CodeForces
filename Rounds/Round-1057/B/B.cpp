#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int x, y, z;
    scanf("%lld%lld%lld", &x, &y, &z);
    int a = x | z, b = x | y, c = y | z;
    bool ans = false;
    if (x == (a & b) && y == (b & c) && z == (a & c)) ans = true;

    printf(ans ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
