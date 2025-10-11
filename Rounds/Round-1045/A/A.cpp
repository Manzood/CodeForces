#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, a, b;
    scanf("%lld%lld%lld", &n, &a, &b);

    bool possible = true;
    if ((n - b) & 1) possible = false;
    if (a > b)
        if ((n - a) & 1) possible = false;

    printf(possible ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
