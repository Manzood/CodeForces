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
    vector<int> ans(n);
    if (n & 1) {
        int val = n - 3;
        ans[0] = n - 1;
        for (int i = 1; i < n - 3; i++) {
            ans[i] = val--;
        }
        ans[n - 2] = n - 2;
        ans[n - 3] = 1;
    } else {
        int val = n - 2;
        for (int i = 0; i < n - 2; i++) {
            ans[i] = val--;
        }
        ans[n - 2] = n - 1;
    }
    ans[n - 1] = n;
    for (auto x : ans) {
        printf("%lld ", x);
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
