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
    bool possible = true;
    vector <int> cnt(n + 1, 0);
    // debug (a);
    for (int i = 0; i < n; i++) {
        while (a[i] >= 1) {
            if (a[i] <= n) {
                cnt[a[i]]++;
            }
            // if (a[i] == 1) debug (i);
            a[i] /= 2;
        }
    }
    // calculate requirements
    vector <int> req(n + 1, 0);
    for (int i = n; i >= 1; i--) {
        int val = i;
        while (val >= 1) {
            req[val]++;
            val /= 2;
        }
    }
    // debug (cnt);
    // debug (req);
    for (int i = 1; i <= n; i++) {
        if (cnt[i] < req[i]) {
            possible = false;
        }
    }
    possible ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
