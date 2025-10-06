#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int N = 101;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<string> a(n);
    map<char, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i][0]]++;
    }

    vector<vector<int>> ncr(N, vector<int>(N));
    for (int i = 0; i < N; i++) ncr[i][0] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= i; j++) {
            ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
        }
    }

    int ans = 0;
    for (auto x : mp) {
        int v1 = x.second / 2;
        int v2 = (x.second + 1) / 2;
        ans += ncr[v1][2];
        ans += ncr[v2][2];
    }

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
