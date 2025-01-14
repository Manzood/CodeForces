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
    vector<int> a(n), b(n);
    bool found = false;
    int ind = -1;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        if (a[i] < b[i]) {
            found = true;
            ind = i;
        }
    }
    if (!found) {
        printf("YES\n");
        return;
    }
    int val = b[ind] - a[ind];
    bool ans = true;
    for (int i = 0; i < n; i++) {
        if (i == ind) continue;
        if (a[i] - val < b[i]) {
            ans = false;
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
