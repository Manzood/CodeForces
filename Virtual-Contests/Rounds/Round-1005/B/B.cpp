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
    vector<int> occ(n + 1, 0);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        occ[a[i]]++;
    }
    int l = -1, l2 = -1;
    int len = 0, len2 = 0;
    for (int i = 0; i < n; i++) {
        if (occ[a[i]] == 1) {
            if (i == 0 || occ[a[i - 1]] != 1) {
                l2 = i;
            }
            len2++;
        } else {
            if (i > 0 && occ[a[i - 1]] == 1) {
                if (len2 > len) {
                    len = len2;
                    l = l2;
                }
                len2 = 0;
            }
        }
    }
    if (len2 > len) {
        len = len2;
        l = l2;
    }
    if (len == 0)
        printf("0\n");
    else
        printf("%lld %lld\n", l + 1, l + len);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
