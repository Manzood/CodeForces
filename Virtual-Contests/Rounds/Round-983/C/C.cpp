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
    sort(a.begin(), a.end());
    int ans = (int)1e9 + 7;
    for (int i = 1; i < n; i++) {
        int moves = i - 1;
        int sum = a[i] + a[i - 1];
        int ind = lower_bound(a.begin(), a.end(), sum) - a.begin();
        moves += n - ind;
        ans = min(moves, ans);
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
