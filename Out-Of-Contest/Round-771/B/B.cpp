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
    int highest_even = 0;
    int highest_odd = 0;
    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            if (a[i] < highest_even) {
                possible = false;
            }
            highest_even = a[i];
        } else {
            if (a[i] < highest_odd) {
                possible = false;
            }
            highest_odd = a[i];
        }
    }
    possible ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
