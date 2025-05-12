#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m, p, q;
    scanf("%lld%lld%lld%lld", &n, &m, &p, &q);

    bool possible = true;
    if (n % p == 0 && n * q / p != m) possible = false;

    printf(possible ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
