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
    vector <int> a(n);
    bool one = false, zero = false;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] == 1) one = true;
        if (a[i] == 0) zero = true;
    }
    bool ans = true;
    if (one && zero) ans = false;
    else if (one) {
        sort (a.begin(), a.end());
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i-1] + 1) ans = false;
        }
    }
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
