#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int eps = (int)1e-6;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    int x1, y1, x2, y2;
    scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    double dist = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    dist = sqrtl(dist);
    double sum = (double)accumulate(a.begin(), a.end(), 0);
    bool possible = true;
    for (int i = 0; i < n; i++) {
        if ((double)a[i] + eps > dist &&
            ((double)a[i] - dist) + eps > (double)(sum - a[i])) {
            possible = false;
        }
    }

    if (dist > sum || !possible) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
