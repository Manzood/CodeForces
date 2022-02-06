#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n, x, y;
    scanf("%lld%lld%lld", &n, &x, &y);
    vector <int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] & 1) cnt++;
    }
    if (y & 1) cnt++;
    if (x & 1) cnt++;
    cnt & 1 ? printf("Bob\n") : printf("Alice\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
