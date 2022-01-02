#include "bits/stdc++.h"
#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif
using namespace std;
#define int long long

// binary search

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld%lld", &a[i], &b[i]);
        }

        int low = 0;
        int high = n;
        int ans = 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            // check if you can get mid people
            int got = 0;
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (mid - got - 1 <= a[i] && got <= b[i]) {
                    got++;
                }
                if (got == mid) {
                    found = true;
                    break;
                }
            }
            if (found) {
                ans = max(mid, ans);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        printf("%lld\n", ans);
    }
}
