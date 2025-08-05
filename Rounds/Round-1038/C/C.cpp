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
    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i][0], &a[i][1]);
        a[i][2] = i;
    }

    sort(a.begin(), a.end());
    sort(a.begin(), a.begin() + n / 2,
         [](vector<int>& x, vector<int>& y) { return x[1] < y[1]; });
    sort(a.begin() + n / 2, a.end(),
         [](vector<int>& x, vector<int>& y) { return x[1] < y[1]; });

    for (int i = 0; i < n / 2; i++) {
        printf("%lld %lld\n", a[i][2] + 1, a[n - i - 1][2] + 1);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
