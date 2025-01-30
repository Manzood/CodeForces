#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    int p = 4 * m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i], &b[i]);
        if (i > 0) {
            p += 2 * (a[i] + b[i]);
        }
    }
    printf("%lld\n", p);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
