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

    int val = -1;
    bool pos = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
            if (val == -1) {
                val = a[i];
            } else {
                if (val != a[i]) pos = false;
            }
        }
    }

    if (val == 0) pos = false;

    pos ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
