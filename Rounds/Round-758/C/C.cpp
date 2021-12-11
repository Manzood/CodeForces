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
        // the logic seems okay?
        int n;
        scanf("%lld", &n);
        vector <pair <pair <int, int>, int>> a(n);
        vector <int> pref(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i].first.first);
            a[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i].first.second);
        }

        // debug (a);
        sort (a.begin(), a.end());
        pref[n-1] = a[n-1].first.second;
        for (int i = n - 2; i >= 0; i--) {
            pref[i] = a[i].first.second;
            pref[i] = min (pref[i], pref[i+1]);
        }
        // debug (a);
        vector <int> ans (n, 0);
        ans[a[n-1].second] = 1;
        int mi = a[n-1].first.second;
        // for (int i = n - 2; i >= 0; i--) {
        //     if (a[i].first.second > mi) {
        //         ans[a[i].second] = 1;
        //     }
        // }

        // debug (pref);
        // debug (mi);
        for (int i = n - 2; i >= 0; i--) {
            // debug (a[i].first.first, a[i].first.second, mi);
            if (a[i].first.second > mi ) {
                ans[a[i].second] = 1;
                mi = pref[i];
            }
        }

        bool found = false;
        for (int i = 0; i < n; i++) {
            if (ans[a[i].second] == 1) {
                found = true;
            }
            if (found) ans[a[i].second] = 1;
        }

        for (int i = 0; i < n; i++) {
            printf("%lld", ans[i]);
        }
        printf("\n");
    }
}
