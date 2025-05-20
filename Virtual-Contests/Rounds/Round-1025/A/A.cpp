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
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    bool possible = sum < n;
    bool f = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (f) {
                possible = false;
            }
            f = true;
        } else {
            f = false;
        }
    }
    printf(possible ? "NO\n" : "YES\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
