#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e18 + 7;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());
    int mi = a[0];
    int g = INF;
    for (int i = 1; i < n; i++) {
        if (a[i] % mi == 0) {
            if (g == INF) {
                g = a[i];
            } else {
                g = __gcd(g, a[i]);
            }
        }
    }
    if (g == mi) {
        printf("Yes\n");
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
