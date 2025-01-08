#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int m, a, b, c;
    scanf("%lld%lld%lld%lld", &m, &a, &b, &c);
    int A = m, B = m;
    A = max(0LL, A - a);
    B = max(0LL, B - b);
    int sub = min(A, c);
    A -= sub, c -= sub;
    sub = min(B, c);
    B -= sub, c -= sub;
    printf("%lld\n", 2 * m - A - B);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
