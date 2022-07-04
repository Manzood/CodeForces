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
    vector<bool> found(n, false);
    vector<bool> left(n, false);
    vector<bool> reserved(n, false);
    vector<int> ans(n, n);
    int mex = 0;
    int left_reserved = 0;
    for (int i = 0; i < n; i++) {
        found[a[i]] = true;
        if (found[mex]) {
            ans[mex] = 1;
            reserved[mex] = true;
            mex++;
            left_reserved++;
            while (found[mex]) {
                ans[mex] = i - (left_reserved - 1);
                left[mex] = true;
                mex++;
            }
        }
    }
    debug(ans);
    found.assign(n, false);
    mex = 0;
    int right_reserved = 0;
    for (int i = n - 1; i >= 0; i--) {
        found[a[i]] = true;
        if (found[mex]) {
            ans[mex] = 1;
            reserved[mex] = true;
            mex++;
            right_reserved++;
            while (found[mex]) {
                ans[mex] = min(ans[mex], n - i - right_reserved);
                mex++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (left[i] && !reserved[i]) {
            ans[i] -= max(right_reserved - 1, 0LL);
        }
    }
    int answer = 1;
    debug(ans);
    int chosen = 0;
    for (int i = 0; i < n; i++) {
        // assert(ans[i] > 0);
        answer *= max(ans[i] - chosen, 1LL);
        if (ans[i] > 1) chosen++;
        answer %= mod;
    }
    printf("%lld\n", answer);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
