#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector <int> ans;
    int val = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (a[i] == 1) {
                val++;
            }
        } else {
            if (__gcd(a[i], a[i-1]) == i + 1) {
            }
        }
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
