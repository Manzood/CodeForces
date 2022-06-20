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
    vector <int> pref(n, 0);
    for (int i = 0; i < n; i++) {
        pref[i] += a[i];
        if (i > 0) pref[i] += pref[i - 1];
    }

    // calculate upper bound using the prefix sum
    int upper = a[0];
    int leftovers = 0;

    for (int i = 1; i < n; i++) {
        if (upper < a[i] - leftovers) {
            int temp = upper;
            temp += (a[i] - leftovers - upper) / (i + 1);
            if ((a[i] - leftovers - upper) % (i + 1) != 0) temp++;
            upper = temp;
        }
        leftovers = upper * (i + 1) - pref[i];
    }

    // for (int i = 0; i < n; i++) {
    //     if (upper < a[i] - leftovers) {
    //         upper = a[i] - leftovers;
    //         leftovers = 0;
    //     } else {
    //         leftovers += upper - a[i];
    //     }
    // }
    // debug(upper);

    // found upper bound, might recheck in the future

    // handle queries
    int q;
    scanf("%lld", &q);
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%lld", &t);
        if (t >= upper) {
            int ans = n;
            // binary search for best value
            int left = 0, right = n - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                // turn on mid + 1 taps
                int l = (mid + 1) * t;
                l -= pref[mid];
                if (pref[n - 1] - pref[mid] > l) {
                    // not found, go right
                    left = mid + 1;
                } else {
                    ans = mid + 1;
                    // found, check left
                    right = mid - 1;
                }
            }
            printf("%lld\n", ans);
        } else {
            printf("-1\n");
        }
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
