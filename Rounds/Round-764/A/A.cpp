#include "bits/stdc++.h"
#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
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
    int mi = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());
    printf("%lld\n", mx - mi);
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
