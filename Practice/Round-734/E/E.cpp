#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        scanf("%lld%lld", &n, &k);
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }

        int ans = 1e9 + 7;
        vector <int> dp(n, 0);
        vector <int> del(n, 1e9 + 7);
        bool found = false;

        for (int i = 0; i < n; i++) {
            // maximum k for the current element
            if (a[i] <= i + 1) {
                int need = i + 1 - a[i];
                for (int j = i - 1; j >= 0; j--) {
                    if (i - j - 1 >= need) {
                        // consider this
                        dp[i] = max (dp[j] + 1, dp[i]);
                    }
                }
            }

            if (dp[i] >= k) {
                // calculate how much you have to delete at minimum
            }
        }
    }
}
