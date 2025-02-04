#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, d;
    scanf("%lld%lld", &n, &d);
    vector<int> ans = {1};
    if (d % 3 == 0 || n > 2) ans.push_back(3);
    if (d == 5) ans.push_back(5);
    if (n > 2 || d == 7) ans.push_back(7);
    if (d % 9 == 0 || n >= 6 || (d % 3 == 0 && n >= 3)) ans.push_back(9);
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
