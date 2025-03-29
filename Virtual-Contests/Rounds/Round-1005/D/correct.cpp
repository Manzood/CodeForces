#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MX = 31;

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int query = 0; query < q; query++) {
        int x;
        scanf("%lld", &x);
        int ind = n;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] > x) break;
            x ^= a[i];
            ind = i;
        }
        printf("%lld ", n - ind);
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
