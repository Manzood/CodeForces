#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<int> a(n), pos(n + 1, -1);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        pos[a[i]] = i;
    }

    for (int query = 1; query <= q; query++) {
        int l, r, x;
        scanf("%lld%lld%lld", &l, &r, &x);
        l--, r--;
        if (pos[x] < l || pos[x] > r) {
            printf("-1 ");
            continue;
        }

        int left = l, right = r;
        int rLess = 0, rMore = 0, usedLess = 0, usedMore = 0;
        int changing = 0;

        while (left < right) {
            int mid = (left + right) / 2;

            if (mid == pos[x]) {
                break;
            } else if (mid < pos[x]) {
                if (a[mid] > x) {
                    changing++;
                    rLess++;
                } else {
                    usedLess++;
                }
                left = mid + 1;
            } else {
                if (a[mid] < x) {
                    changing++;
                    rMore++;
                } else {
                    usedMore++;
                }
                right = mid - 1;
            }
        }

        bool possible = true;
        int req = max(rLess, rMore) - min(rLess, rMore);
        if (rLess < rMore) {
            if (req + rLess + usedMore > n - x) {
                possible = false;
            }
        } else {
            if (req + rMore + usedLess > x - 1) {
                possible = false;
            }
        }
        changing += req;

        if (possible) {
            printf("%lld ", changing);
        } else {
            printf("-1 ");
        }
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
