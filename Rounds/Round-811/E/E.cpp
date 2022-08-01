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
    for (int i = 0; i < n; i++) {
        if (a[i] % 5 == 0) {
            if (a[i] % 10) a[i] += 5;
        } else {
            while ((a[i] % 10) != 2) {
                a[i] += (a[i] % 10);
            }
        }
    }
    int comp = a[0];
    bool ans = true;
    for (int i = 1; i < n; i++) {
        int diff = abs(comp - a[i]);
        if (diff % 20 != 0) {
            ans = false;
        }
        if (comp % 10 == 0 || a[i] % 10 == 0) {
            if (a[i] != comp) ans = false;
        }
    }
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
