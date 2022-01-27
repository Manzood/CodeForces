#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector <int> last(n + 1, -1);
    for (int i = 0; i < n; i++) {
        last[a[i]] = i;
    }
    int ans = 0;
    int s = 0;
    vector <int> end;
    int endind = -1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if ((int) end.size() > 0 && i == end[endind]) {
            ans += end[endind] - s - 1 - cnt;
            endind++;
            cnt = 0;
        }
        int e;
        if ((int) end.size() < endind) {
            e = -1;
        } else {
            e = end[(int) end.size() - 1];
        }
        if (last[a[i]] > e) {
            if ((int) end.size() == endind) {
                s = i;
                end.push_back(last[a[i]]);
            } else if (endind + 1 == (int) end.size()) {
                end.push_back (last[a[i]]);
            } else {
                end[end.size() - 1] = last[a[i]];
                cnt = 1;
            }
        }

        // if (last[a[i]] > e) {
        //     if (e > -1) twice = true;
        //     e = last[a[i]];
        // }
        // if (s == -1) {
        //     if (e > -1) s = i;
        // }
        // if (i == e) {
        //     // reached the end
        //     if (twice) {
        //         if (e > s + 1) ans += e - s - 2;
        //     } else {
        //         if (e > s + 1) ans += e - s - 1;
        //     }
        //     s = -1;
        //     e = -1;
        //     twice = false;
        // }
        // debug (i, s, e, ans);
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
