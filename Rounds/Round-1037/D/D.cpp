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
    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld%lld", &a[i][0], &a[i][2], &a[i][1]);
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (k >= a[i][0] && k < a[i][1]) {
            k = a[i][1];
        }
    }

    printf("%lld\n", k);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
