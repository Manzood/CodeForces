#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, x;
    scanf("%lld%lld", &n, &x);
    vector<int> a(n);
    iota(a.begin(), a.end(), 0);
    if (x < n) {
        swap(a[x], a[n - 1]);
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", a[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
