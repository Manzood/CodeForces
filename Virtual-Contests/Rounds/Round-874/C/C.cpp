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
    bool pos = true;
    bool all_even = true;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i] & 1) {
            all_even = false;
        } else {
            if (!(a[0] & 1)) {
                pos = false;
            }
        }
    }
    bool ans = false;
    if (pos || all_even) ans = true;
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
