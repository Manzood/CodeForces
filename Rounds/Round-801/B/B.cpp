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
    int evenmin = (int) 1e9 + 7, oddmin = (int) 1e9 + 7;
    int eindex = -1, oindex = -1;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (i % 2 == 0) {
            if (a[i] < evenmin) eindex = i;
            evenmin = min(a[i], evenmin);
        } else {
            if (a[i] < oddmin) oindex = i;
            oddmin = min(a[i], oddmin);
        }
    }
    bool mike = true;
    if (n % 2 == 0) {
        if (evenmin < oddmin) mike = false;
        else if (evenmin == oddmin && oindex > eindex) mike = false;
    }
    mike ? printf("Mike\n") : printf("Joe\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
