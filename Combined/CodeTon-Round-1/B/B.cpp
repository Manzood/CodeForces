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
    vector <int> a(n);
    set <int> nums;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        nums.insert(a[i]);
    }
    bool ans = false;
    for (int i = 0; i < n; i++) {
        if (nums.count(a[i] - k)) ans = true;
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
