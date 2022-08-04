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
    iota(ans.begin(), ans.end(), 1);
    printf("%lld\n", n);
    for (auto x : ans) {
        printf("%lld ", x);
    }
    printf("\n");
    int index = n - 2;
    for (int i = 1; i < n; i++) {
        swap(ans[n - 1], ans[index]);
        index--;
        for (auto x : ans) {
            printf("%lld ", x);
        }
        printf("\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
