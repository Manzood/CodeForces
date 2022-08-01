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
    set<int> nums;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int len = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (nums.count(a[i])) {
            break;
        }
        len++;
        nums.insert(a[i]);
    }
    int ans = n - len;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
