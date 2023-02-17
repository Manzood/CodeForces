#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int x, y;
    scanf("%lld%lld", &x, &y);
    vector<int> ans;
    ans.push_back(x);
    for (int i = x - 1; i >= y; i--) {
        ans.push_back(i);
    }
    for (int i = y + 1; i < x; i++) {
        ans.push_back(i);
    }
    int n = (int)ans.size();
    printf("%lld\n", n);
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
