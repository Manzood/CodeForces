#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    if (k >= sum) {
        printf("%lld\n", n);
        return;
    }
    int sunk = 0;
    int rem = k / 2 + (k & 1);
    for (int i = 0; i < n; i++) {
        if (a[i] > rem) break;
        sunk++;
        rem -= a[i];
    }
    rem = k / 2;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > rem) break;
        sunk++;
        rem -= a[i];
    }
    printf("%lld\n", sunk);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
