#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    bool possible = true;
    if (m < n) possible = false;
    if (!(n & 1) && (m & 1)) possible = false;
    vector<int> ans(n);
    if (n & 1) {
        for (int i = 0; i < n - 1; i++) {
            ans[i] = 1;
        }
        ans[n - 1] = m - (n - 1);
    } else {
        for (int i = 0; i < n - 2; i++) {
            ans[i] = 1;
        }
        ans[n - 1] = (m - (n - 2)) / 2;
        ans[n - 2] = (m - (n - 2)) / 2;
    }
    if (possible) {
        printf("Yes\n");
        for (auto x : ans) {
            printf("%lld ", x);
        }
        printf("\n");
    } else {
        printf("No\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
