#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());
    int f = 0, e = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == a[0]) f++;
        if (a[i] == a[n - 1]) e++;
    }
    int ans = f * e * 2;
    if (a[0] == a[n - 1]) {
        ans = n * (n - 1);
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
