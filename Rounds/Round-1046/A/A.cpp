#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int a, b, c, d;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);

    bool possible = true;
    if (a > 2 * b + 2 || b > 2 * a + 2) possible = false;
    c -= a;
    d -= b;
    if (c > 2 * d + 2 || d > 2 * c + 2) possible = false;

    printf(possible ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
