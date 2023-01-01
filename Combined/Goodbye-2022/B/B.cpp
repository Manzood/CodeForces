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
    int s = 1, e = n;
    vector<int> ans;
    while (s < e) {
        ans.push_back(e);
        ans.push_back(s);
        s++;
        e--;
    }
    if (s == e) ans.push_back(s);
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
