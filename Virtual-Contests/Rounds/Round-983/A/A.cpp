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
    vector<int> a(2 * n);
    int sum = 0;
    for (int i = 0; i < 2 * n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    int mi = sum & 1;
    int mx = 0;
    if (sum <= n) {
        mx = sum;
    } else {
        mx = 2 * n - sum;
    }
    printf("%lld %lld\n", mi, mx);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
