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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int mi = min(a[0], a[n - 1]);
    int l = 0, r = n - 1;
    bool ans = true;
    while (l <= r) {
        if (a[l] < a[r]) {
            if (a[l] < mi) ans = false;
            mi = a[l];
            l++;
        } else {
            if (a[r] < mi) ans = false;
            mi = a[r];
            r--;
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
