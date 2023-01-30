#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, s, r;
    scanf("%lld%lld%lld", &n, &s, &r);
    int highest = s - r;
    vector<int> ans = {highest};
    int rem = r / (n - 1);
    int other = r % (n - 1);
    if (test == 2) debug(other);
    for (int i = 0; i < other; i++) {
        ans.push_back(rem + 1);
    }
    while ((int)ans.size() < n) ans.push_back(rem);
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
