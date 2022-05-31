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
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector <int> mxr(n, 0); // stores the maximum subarray sum to the right
    vector <int> mxl(n, 0); // stores the maximum subarray sum to the left
    vector <int> pref(n + 1, 0);
    vector <int> suff(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i];
        pref[i + 1] += a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        suff[i] = suff[i + 1];
        suff[i] += a[i];
        if (i <= n - 2) mxr[i] = max(pref[i + 2], mxr[i]);
        if (i <= n - 2) mxr[i] = max(mxr[i + 1], mxr[i]);
    }
    for (int i = 1; i < n; i++) {
        mxl[i] = mxl[i - 1];
        mxl[i] = max(mxl[i], suff[i - 1]);
    }
    bool ans = true;
    for (int i = 0; i < n; i++) {
        // if (mxl[i] > 0 || mxr[i] > 0) {
        //     debug(test, i, mxl[i], mxr[i], a[i]);
        //     ans = false;
        // }
    }
    printf(ans ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
