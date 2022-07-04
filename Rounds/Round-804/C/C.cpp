#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int mod = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<bool> found(n + 1, false);
    vector<int> left(n, 0);
    vector<int> right(n, n - 1);
    vector<bool> reserved(n, false);
    int mex = 0;
    for (int i = 0; i < n; i++) {
        found[a[i]] = true;
        if (found[mex]) {
            left[mex] = i;
            right[mex] = i;
            reserved[mex] = true;
            mex++;
            while (found[mex]) {
                right[mex] = i - 1;
                mex++;
            }
        }
    }
    found.assign(n, false);
    mex = 0;
    for (int i = n - 1; i >= 0; i--) {
        found[a[i]] = true;
        if (found[mex]) {
            left[mex] = i;
            right[mex] = i;
            reserved[mex] = true;
            mex++;
            while (found[mex]) {
                if (!reserved[mex]) left[mex] = i + 1;
                mex++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (left[i] == right[i]) reserved[i] = true;
    }
    vector<int> pref(n, 0);
    for (int i = 0; i < n; i++) {
        if (i > 0) pref[i] = pref[i - 1];
        if (reserved[a[i]]) pref[i]++;
    }
    int ans = 1LL;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int val = right[i] - left[i] + 1;
        int leftval = left[i] > 0 ? pref[left[i] - 1] : 0LL;
        int rightval = pref[right[i]];
        val -= max(rightval - leftval, 0LL);
        val = max(val - count, 1LL);
        ans *= val;
        ans %= mod;
        if (val > 1) count++;
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
