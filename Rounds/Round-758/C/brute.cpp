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
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i].first.first);
            a[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i].first.second);
        }

        // debug (a);
        sort (a.begin(), a.end());
        // debug (a);
        vector <int> ans (n, 0);
        ans[a[n-1].second] = 1;
        int mi = a[n-1].first.second;
        for (int i = n - 2; i >= 0; i--) {
            if (a[i].first.second > mi) {
                ans[a[i].second] = 1;
            }
        }
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (ans[a[i].second] == 1) {
                found = true;
            }
            if (found) ans[a[i].second] = 1;
        }

        bool changed = false;
        do {
            changed = false;
            for (int i = 0; i < n; i++) {
                if (ans[a[i].second] == 1) {
                    mi = min (a[i].first.second, mi);
                }
            }
            for (int i = n - 2; i >= 0; i--) {
                if (a[i].first.second > mi) {
                    if (ans[a[i].second] == 0) changed = true;
                    ans[a[i].second] = 1;
                }
            }
            found = false;
            for (int i = 0; i < n; i++) {
                if (ans[a[i].second] == 1) {
                    found = true;
                }
                if (found && ans[a[i].second] == 0) changed = true;
                if (found) ans[a[i].second] = 1;
            }
        } while (changed);

        for (int i = 0; i < n; i++) {
            printf("%lld", ans[i]);
        }
        printf("\n");
    }
}

