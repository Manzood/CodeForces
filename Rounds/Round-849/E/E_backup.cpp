#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e18;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    int negative = 0;
    int sum = 0;
    int mi = INF;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] < 0) negative++;
        sum += abs(a[i]);
        mi = min(mi, abs(a[i]));
    }
    int ans = sum;
    if (negative & 1) ans -= 2 * mi;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
