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
    vector<vector<int>> a(n, vector<int>(n - 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    vector<int> cnt(n + 1, 0);
    int f = -1;
    for (int i = 0; i < n; i++) {
        cnt[a[i][0]]++;
        if (cnt[a[i][0]] > 1) f = a[i][0];
    }
    int ind = -1;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] == f) found = true;
        }
        if (!found) ind = i;
    }
    printf("%lld ", f);
    for (int i = 1; i < n; i++) {
        printf("%lld ", a[ind][i - 1]);
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
