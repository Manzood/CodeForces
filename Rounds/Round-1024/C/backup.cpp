#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    vector<int> b, index;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] > 1) {
            b.push_back(a[i]);
            index.push_back(i);
        }
    }

    int l = 0, r = (int)b.size() - 1;
    vector<bool> usedInd(n, false);
    set<int> rem;
    for (int i = 2; i <= n; i++) rem.insert(i);
    int ans = 0;
    while (l < r) {
        int mi = min(b[l], b[r]);
        // find the largest unused value so far
        // probably with a set
        // add the distance to answer
        // if no such unused value, do nothing

        auto it = upper_bound(rem.begin(), rem.end(), mi);
        if (it != rem.begin()) {
            it--;
            ans += index[r] - index[l];
            usedInd[index[r]] = true;
            usedInd[index[l]] = true;
            rem.erase(it);
        }

        l++, r--;
    }

    if (test == 4) {
        debug(b, index);
        debug(usedInd);
    }
    int prev = -1, val = 0;
    for (int i = 0; i < n; i++) {
        if (!usedInd[i]) {
            if (prev == -1) {
                prev = i;
            } else {
                val = max(val, i - prev);
            }
        }
    }
    ans += val;

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
