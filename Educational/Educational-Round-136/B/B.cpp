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
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> o(n);
    bool possible = true;
    o[0] = a[0];
    for (int i = 1; i < n; i++) {
        o[i] = o[i - 1] + a[i];
        if (o[i - 1] - a[i] >= 0 && a[i] != 0) {
            possible = false;
        }
    }
    if (possible) {
        for (auto x : o) {
            printf("%lld ", x);
        }
        printf("\n");
    } else {
        printf("-1\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
