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
        int n;
        scanf("%lld", &n);
        vector <int> l(n), r(n), c(n);
        int l_ind, r_ind;
        int cost = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lld%lld%lld", &l[i], &r[i], &c[i]);
        }
        l_ind = 0;
        r_ind = 0;
        vector <int> ans;
        int widest_r = 0, widest_l = 0;
        for (int i = 0; i < n; i++) {
            if (l[l_ind] > l[i]) {
                l_ind = i;
                widest_l = i;
            } else if (l[l_ind] == l[i]) {
                // pick least cost
                if (c[l_ind] > c[i]) {
                    l_ind = i;
                }
                if (r[widest_l] < r[i]) {
                    widest_l = i;
                } else if (r[widest_l] == r[i]) {
                    if (c[widest_l] > c[i]) {
                        widest_l = i;
                    }
                }
            }
            if (r[r_ind] < r[i]) {
                r_ind = i;
                widest_r = i;
            } else if (r[r_ind] == r[i]) {
                if (c[r_ind] > c[i]) {
                    r_ind = i;
                }
                if (l[widest_r] > l[i]) {
                    widest_r = i;
                } else if (l[widest_r] == l[i]) {
                    if (c[widest_r] > c[i]) {
                        widest_r = i;
                    }
                }
            }

            if (l_ind == r_ind) {
                cost = c[l_ind];
            } else {
                cost = c[l_ind];
                cost += c[r_ind];
            }

            // debug (l[i], r[i]);
            // debug (widest_l, widest_r);
            if (l[widest_l] == l[widest_r] && r[widest_r] > r[widest_l]) {
                // pick only rightmost
                cost = min(cost, c[widest_r]);
            } else if (r[widest_r] == r[widest_l] && l[widest_l] < l[widest_r]) {
                cost = min(cost, c[widest_l]);
            } else if (l[widest_l] == l[widest_r] && r[widest_l] == r[widest_r]){
                cost = min(cost, min(c[widest_l], c[widest_r]));
            }

            ans.push_back (cost);
        }

        for (int i = 0; i < n; i++) {
            printf("%lld\n", ans[i]);
        }
    }
}
