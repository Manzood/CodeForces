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
    bool ans = false;
    int ind1 = -1, ind2 = -1;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (i > 0 && abs(a[i] - a[i - 1]) >= 2) {
            ans = true;
            ind1 = i - 1;
            ind2 = i;
        }
    }
    if (ans) {
        printf("YES\n");
        printf("%lld %lld\n", ind1 + 1, ind2 + 1);
    } else {
        printf("NO\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
