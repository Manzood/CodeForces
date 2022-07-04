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
    vector<int> perm(n);
    int count = 0;
    iota(perm.begin(), perm.end(), 0);
    do {
        // find mex
        bool found = true;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // mex for i, j inclusive
                int mex1 = 0;
                vector<bool> f(n, false);
                for (int x = i; x <= j; x++) {
                    f[a[x]] = true;
                    while (f[mex1]) mex1++;
                }
                f.assign(n, false);
                int mex2 = 0;
                for (int x = i; x <= j; x++) {
                    f[perm[x]] = true;
                    while (f[mex2]) mex2++;
                }
                if (mex1 != mex2) found = false;
            }
        }
        if (found) count++;
    } while (next_permutation(perm.begin(), perm.end()));
    printf("%lld\n", count);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
