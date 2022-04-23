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
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector <int> next(n, -1);
    int cur = 0;
    for (int i = 0; i < n; i++) {

    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
