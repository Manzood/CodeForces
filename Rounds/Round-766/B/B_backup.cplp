#include "bits/stdc++.h"
using namespace std;

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

#define int long long

void solve() {
    int n, m;
    scanf("%lld%lld", &n, &m);
    int sum = (n % 2) + (m % 2);
    int val = 0;
    int add;
    int dist = 0;
    int xdim = 0;
    int ydim = 0;
    if (sum == 0) {
        val = 4;
        add = 8;
        xdim = 2;
        ydim = 2;
    } else if (sum == 1) {
        val = 2;
        add = 6;
        if (n % 2 == 0) {
            xdim = 2;
            ydim = 1;
        } else {
            xdim = 1;
            ydim = 2;
        }
    } else {
        val = 1;
        add = 4;
        xdim = 1;
        ydim = 1;
    }
    dist = n / 2 + m / 2;
    vector <int> ans;
    for (int i = 0; i < val; i++) {
        // fill out centre
        ans.push_back (dist);
    }
    dist++;
    int cur = 0;
    int sub1 = 0;
    int sub2 = 0;
    // int ysum = 2;
    // int xsum = 2;
    // debug(add);
    while (++val <= n * m) {
        cur++;
        ans.push_back (dist);
        if (cur == add) {
            xdim += 2;
            ydim += 2;
            if (xdim == m) {
                sub1 = 2;
            } else if (xdim > m) {
                sub1 = 4;
            }
            if (ydim == n) {
                sub2 = 2;
            } else if (ydim > n) {
                sub2 = 4;
            }
            cur = 0;
            debug(add);
            add += 4;
            add -= sub1;
            add -= sub2;
            dist++;
            debug (n, add);
            debug (sub1, sub2);
        }
    }
    for (int i = 0; i < (int) ans.size(); i++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
