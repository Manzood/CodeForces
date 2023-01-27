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
    int o = 0;
    int i = -1, j = -1, k = -1;
    for (int x = 0; x < n; x++) {
        scanf("%lld", &a[x]);
        if (a[x] & 1) {
            o++;
            if (i > -1 && j > -1)
                k = x;
            else if (i > -1)
                j = x;
            else
                i = x;
        }
    }
    bool ans = false;
    if (o >= 3) {
        ans = true;
    } else if (o >= 1 && n - o >= 2) {
        ans = true;
        j = 0;
        while (a[j] & 1) j++;
        k = 0;
        while (a[k] & 1 || k == j) k++;
    }
    ans ? printf("YES\n") : printf("NO\n");
    if (ans) {
        printf("%lld %lld %lld\n", i + 1, j + 1, k + 1);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
