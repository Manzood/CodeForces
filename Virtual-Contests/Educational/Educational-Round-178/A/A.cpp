#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n = 3;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    a[2] -= (a[1] - a[0]);
    bool possible = a[2] >= a[1];
    if (a[2] > a[1]) {
        if ((a[2] - a[1]) % 3 != 0) possible = false;
    }
    printf(possible ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
