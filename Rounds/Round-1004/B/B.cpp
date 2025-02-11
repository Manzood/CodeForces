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
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] != 0) ans++;
    }
    int ind = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            ind = i;
            break;
        }
    }
    if (ind != -1) {
        int cnt = 0;
        set<int> s;
        for (int i = n - 1; i >= ind; i--) {
            if (i != ind && a[i] == 0) continue;
            cnt++;
            s.insert(a[i]);
        }
        int mex = 0;
        while (s.count(mex)) mex++;
        for (int i = ind - 1; i >= 0; i--) {
            if (a[i] >= mex) {
                cnt++;
                s.insert(a[i]);
            }
            while (s.count(mex)) mex++;
        }
        ans = max(ans, cnt);
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
