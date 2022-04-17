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
    vector <int> A(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &A[i]);
    }
    int c = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += b * (A[i] - c);
        // consider moving
        if (b * (n - i) > a) {
            ans += a * (A[i] - c);
            c = A[i];
        }
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
