#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<vector<int>> adj(n);
    vector<int> p(n, -1);
    for (int i = 1; i < n; i++) {
        int parent;
        scanf("%lld", &parent);
        p[i] = parent - 1;
        adj[parent - 1].push_back(i);
    }
    // dfs isn't even necessary
    int low = 1;
    int high = n - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        vector<int> h(n);
        int moves = 0;
        // handle case for 1
        for (int i = n - 1; i >= 1; i--) {
            if (p[i] != 0 && h[i] == mid - 1) {
                moves++;
                h[i] = -1;
            }
            h[p[i]] = max(h[p[i]], h[i] + 1);
        }
        if (mid == 1) {
            moves = 0;
            for (int i = 1; i < n; i++) {
                if (p[i] != 0) moves++;
            }
        }
        if (moves <= k) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    printf("%lld\n", high);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
