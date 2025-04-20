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
    vector<pair<int, int>> a(n);
    map<int, int> x, diag;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i].first, &a[i].second);
        x[a[i].first]++;
        diag[a[i].first + a[i].second]++;
    }
    int ansX = -1, ansY = -1;
    for (auto cur : x) {
        if (cur.second & 1) {
            ansX = cur.first;
        }
    }
    for (auto cur : diag) {
        if (cur.second & 1) {
            ansY = cur.first - ansX;
        }
    }
    printf("%lld %lld\n", ansX, ansY);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
