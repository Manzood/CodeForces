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
    vector<int> a(n), freq(n + 1, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        freq[a[i]]++;
    }
    int mx = 1;
    for (int i = 0; i <= n; i++) {
        mx = max(mx, freq[i]);
    }
    printf("%lld\n", n - mx);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
