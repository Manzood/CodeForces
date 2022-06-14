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
    vector <int> a(n);
    set <int> s;
    int repeats = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (s.count(a[i])) {
            repeats++;
        }
        s.insert(a[i]);
    }
    int ans = 0;
    (repeats & 1) ? ans = n - repeats - 1 : ans = n - repeats;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
