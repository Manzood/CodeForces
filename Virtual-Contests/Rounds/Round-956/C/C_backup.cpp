#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool check(int ind, int n) {
    if (ind < 0 || ind >= n) return false;
    return true;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n), b(n), c(n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        tot += a[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &c[i]);
    }
    int val = (tot + 2) / 3;
    vector<vector<int>> left(3, vector<int>(n)), right(3, vector<int>(n)),
        pref(3, vector<int>(n, 0));
    pref[0][0] = a[0];
    pref[1][0] = b[0];
    pref[2][0] = c[0];
    for (int i = 1; i < n; i++) {
        pref[0][i] = pref[0][i - 1] + a[i];
        pref[1][i] = pref[1][i - 1] + b[i];
        pref[2][i] = pref[2][i - 1] + c[i];
    }
    for (int i = 0; i < n; i++) {
        int cur = i == 0 ? 0 : pref[0][i - 1];
        right[0][i] = lower_bound(pref[0].begin(), pref[0].end(), cur + val) -
                      pref[0].begin();
        cur = pref[0][i];
        // if (test == 5 && i == 1) debug(cur, val);
        left[0][i] = upper_bound(pref[0].begin(), pref[0].end(), cur - val) -
                     pref[0].begin();
        if (pref[0][i] - (left[0][i] > 0 ? pref[0][left[0][i] - 1] : 0LL) < val)
            left[0][i] = -1;
        // for b
        cur = i == 0 ? 0 : pref[1][i - 1];
        right[1][i] = lower_bound(pref[1].begin(), pref[1].end(), cur + val) -
                      pref[1].begin();
        cur = pref[1][i];
        left[1][i] = upper_bound(pref[1].begin(), pref[1].end(), cur - val) -
                     pref[1].begin();
        if (pref[1][i] - (left[1][i] > 0 ? pref[1][left[1][i] - 1] : 0LL) < val)
            left[1][i] = -1;
        // for c
        cur = i == 0 ? 0 : pref[2][i - 1];
        right[2][i] = lower_bound(pref[2].begin(), pref[2].end(), cur + val) -
                      pref[2].begin();
        cur = pref[2][i];
        left[2][i] = upper_bound(pref[2].begin(), pref[2].end(), cur - val) -
                     pref[2].begin();
        if (pref[2][i] - (left[2][i] > 0 ? pref[2][left[2][i] - 1] : 0LL) < val)
            left[2][i] = -1;
    }
    pair<int, int> ansA, ansB, ansC;
    bool found = false;
    for (int i = 0; i < n; i++) {
        int ind = right[0][i];
        if (check(ind + 1, n)) {
            // try both right side
            int indb = right[1][ind + 1];
            if (check(indb + 1, n)) {
                int indc = right[2][indb + 1];
                if (check(indc, n)) {
                    found = true;
                    ansA = {i, ind};
                    ansB = {ind + 1, indb};
                    ansC = {indb + 1, indc};
                }
            }
            int indc = right[2][ind + 1];
            if (check(indc + 1, n)) {
                indb = right[1][indc + 1];
                if (check(indb, n)) {
                    found = true;
                    ansA = {i, ind};
                    ansB = {indc + 1, indb};
                    ansC = {ind + 1, indc};
                }
            }
            // both on the left
            if (i > 0) {
                indb = left[1][i - 1];
                if (check(indb - 1, n)) {
                    indc = left[2][indb - 1];
                    if (check(indc, n)) {
                        found = true;
                        ansA = {i, ind};
                        ansB = {indb, i - 1};
                        ansC = {indc, indb - 1};
                    }
                }
                indc = left[2][i - 1];
                if (check(indc - 1, n)) {
                    indb = left[1][indc - 1];
                    if (check(indb, n)) {
                        found = true;
                        ansA = {i, ind};
                        ansB = {indb, indc - 1};
                        ansC = {indc, i - 1};
                    }
                }
            }
            // both on either side
            if (i > 0) {
                indb = left[1][i - 1];
                indc = right[2][ind + 1];
                if (check(indb, n) && check(indc, n)) {
                    found = true;
                    ansA = {i, ind};
                    ansB = {indb, i - 1};
                    ansC = {ind + 1, indc};
                }
                indb = right[1][ind + 1];
                indc = left[2][i - 1];
                if (check(indb, n) && check(indc, n)) {
                    found = true;
                    ansA = {i, ind};
                    ansB = {ind + 1, indb};
                    ansC = {indc, i - 1};
                }
            }
        }
    }
    if (!found) {
        printf("-1\n");
        return;
    }
    printf("%lld %lld %lld %lld %lld %lld\n", ansA.first + 1, ansA.second + 1,
           ansB.first + 1, ansB.second + 1, ansC.first + 1, ansC.second + 1);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
