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
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector <int> smallest(n), biggest(n);
    for (int i = 0; i < n; i++) {
        biggest[i] = i == 0 ? a[i] : max(biggest[i-1], a[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        smallest[i] = i == n - 1 ? a[i] : min(smallest[i+1], a[i]);
    }
    int ans = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (smallest[i] < smallest[i+1] && biggest[i] <= smallest[i+1]) {
            ans++;
        }
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
