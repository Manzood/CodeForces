#include "bits/stdc++.h"

#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif

using namespace std;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int k, x;
        scanf("%lld%lld", &k, &x);
        // x = (int)1e18;
        int ans =  -1;
        // debug (k, x);
        if (x >= (k * k)) {
            printf("%lld\n", 2 * k - 1);
            continue;
        }

        if (x > (k * (k + 1)) / 2) {
            // second half
            x -= (k * (k + 1)) / 2;
            int low = 0;
            int high = k;
            x = (((k - 1) * k) / 2) - x;
            x++;
            while (1) {
                int mid = (low + high) / 2;
                if (mid * (mid + 1) > 2 * x) {
                    high = mid - 1;
                } else {
                    if ((mid + 1) * (mid + 2) > 2 * x) {
                        // found our value
                        if (mid * (mid + 1) < 2 * x) {
                            ans = mid + 1;
                        } else {
                            ans = mid;
                        }
                        // found = true;
                        break;
                    } else {
                        low = mid + 1;
                    }
                }
            }
            ans = 2 * k - ans;
        } else {
            // first half
            // binary search
            // find sqrt (x)
            int low = 0;
            int high = k;
            while (1) {
                int mid = (low + high) / 2;
                if (mid * (mid + 1) > 2 * x) {
                    high = mid - 1;
                } else {
                    if ((mid + 1) * (mid + 2) > 2 * x) {
                        // found our value
                        if (mid * (mid + 1) < 2 * x) {
                            ans = mid + 1;
                        } else {
                            ans = mid;
                        }
                        break;
                    } else {
                        low = mid + 1;
                    }
                }
            }
        }
        printf("%lld\n", ans);
    }
}
