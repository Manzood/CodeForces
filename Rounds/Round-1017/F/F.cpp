#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    vector<int> perm(k), shifted(k);
    iota(perm.begin(), perm.end(), 1);
    for (int i = 0; i < k - 1; i++) {
        shifted[i + 1] = perm[i];
    }
    shifted[0] = perm[k - 1];
    int ind = 0;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = perm[ind];
            ind = (ind + 1) % k;
        }
    }
    for (int i = 1; i < n; i++) {
        if (a[i][0] == a[i - 1][0]) {
            ind = 0;
            for (int j = 0; j < m; j++) {
                a[i][j] = shifted[ind];
                ind = (ind + 1) % k;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%lld ", a[i][j]);
        }
        printf("\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
