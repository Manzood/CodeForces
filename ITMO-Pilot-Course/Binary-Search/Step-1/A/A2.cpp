#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int j = 0; j < k; j++) {
        int target;
        scanf("%lld", &target);
        int jump = n / 2;
        int ind = 0;
        bool found = false;
        while (1) {
            if (a[ind + jump] < target) ind += jump;
            if (a[ind + jump] == target) {
                found = true;
                break;
            }
            if (jump == 0) break;
            jump /= 2;
        }
        printf(found ? "YES\n" : "NO\n");
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
