#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector <int> partner(n);
    vector <int> visited(n, false);
    for (int i = 0; i < n; i++) {
        partner[i] = n - 1 - i;
    }
    if (k < n - 1) {
        int l = partner[k];
        partner[l] = 0;
        partner[n-1] = k;
        partner[k] = n - 1;
        partner[0] = l;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                assert(!visited[partner[i]]);
                printf("%lld %lld\n", i, partner[i]);
                visited[i] = true;
                visited[partner[i]] = true;
            }
        }
    } else {
        if (n > 4) {
            int val = n / 2 - 1;
            partner[n-1] = val;
            partner[partner[val]] = 0;
            partner[0] = partner[val];
            partner[val] = n-1;
            // now swap n - 2 and 1
            val = n / 2;
            partner[val] = n - 2;
            partner[n - 2] = val;
            partner[1] = 0;
            partner[0] = 1;
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    assert(!visited[partner[i]]);
                    printf("%lld %lld\n", i, partner[i]);
                    visited[i] = true;
                    visited[partner[i]] = true;
                }
            }
        } else {
            printf("-1\n");
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
