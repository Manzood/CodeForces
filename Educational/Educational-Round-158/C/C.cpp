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
    int mi = (int)1e9 + 7, mx = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        mi = min(a[i], mi);
        mx = max(a[i], mx);
    }
    int moves = 0;
    vector<int> ans;
    while (mx > mi) {
        mx = (mx + mi) / 2;
        if ((int)ans.size() < n) {
            ans.push_back(mi);
        }
        moves++;
    }
    printf("%lld\n", moves);
    if (moves <= n) {
        for (auto x : ans) {
            printf("%lld ", x);
        }
        if (moves > 0) printf("\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
