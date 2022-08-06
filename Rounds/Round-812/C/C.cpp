#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int get_next(int n) {
    int val = 0;
    while (val * val < n) val++;
    return val * val;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> ans(n);
    vector<bool> used(n + 1, false);
    int target = n;
    int cur = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (i < target) {
            int required = get_next(i);
            target = required - i;
            cur = target;
        }
        ans[i] = cur++;
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", ans[i]);
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
