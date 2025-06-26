#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, s;
    scanf("%lld%lld", &n, &s);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());

    int ans = min(2 * (a[n - 1] - s) + s - a[0], a[n - 1] - s + 2 * (s - a[0]));

    if (s <= a[0])
        ans = a[n - 1] - s;
    else if (s >= a[n - 1])
        ans = s - a[0];

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
