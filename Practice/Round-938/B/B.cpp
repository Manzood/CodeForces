#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, c, d;
    scanf("%lld%lld%lld", &n, &c, &d);
    vector<int> a(n * n), b(n * n);
    for (int i = 0; i < n * n; i++) {
        scanf("%lld", &b[i]);
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[n * i + j] = b[0] + (c * i) + (d * j);
        }
    }
    sort(a.begin(), a.end());
    a == b ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
