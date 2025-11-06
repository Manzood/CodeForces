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
    vector<int> a(n), out(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        out[i] = n + 1 - a[i];
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", out[i]);
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
