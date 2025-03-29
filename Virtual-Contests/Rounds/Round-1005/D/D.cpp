#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MX = 31;

void solve([[maybe_unused]] int test) {
    // weird bit lookups
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<vector<int>> latest(n, vector<int>(MX, -1));
    vector<int> highest(n, -1), suff(n + 1, 0);

    for (int i = 0; i < n; i++) {
        bool found = false;
        if (i > 0) latest[i] = latest[i - 1];
        for (int j = MX; j >= 0; j--) {
            if (a[i] & (1LL << j)) {
                highest[i] = max(highest[i], j);
                found = true;
            }
            if (found) {
                latest[i][j] = i;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        suff[i] = suff[i + 1] ^ a[i];
    }

    for (int query = 0; query < q; query++) {
        int x;
        scanf("%lld", &x);
        int cur = MX - 1, ind = n, cpy = x;

        while (cur >= 0) {
            if (ind == 0) break;
            x = cpy ^ suff[ind];
            while (cur >= 0 && !((1LL << cur) & x)) cur--;
            if (cur < 0) break;

            int index = latest[ind - 1][cur];
            ind = index + 1;
            if (highest[index] > cur) break;
            if (ind == 0) break;

            // clash
            x = cpy ^ suff[ind];
            if (cur == 0) ind = index;
            while (cur >= 0) {
                cur--;
                int v = (1LL << cur);
                if (!((v & a[index]) && (v & x))) {
                    if (v & a[index]) {
                        cur = -1;
                    } else if (v & x) {
                        ind = index;
                        break;
                    }
                }
                if (cur == 0) ind = index;
            }
        }

        printf("%lld ", n - ind);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
