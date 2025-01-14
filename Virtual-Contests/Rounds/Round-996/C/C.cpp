#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    string s;
    cin >> s;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> rsum(n, 0), csum(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lld", &a[i][j]);
            rsum[i] += a[i][j];
            csum[j] += a[i][j];
        }
    }
    pair<int, int> pos = {0, 0};
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'D') {
            int val = -rsum[pos.first];
            a[pos.first][pos.second] = val;
            csum[pos.second] += val;
            pos.first++;
        } else {
            int val = -csum[pos.second];
            a[pos.first][pos.second] = val;
            rsum[pos.first] += val;
            pos.second++;
        }
    }
    a[pos.first][pos.second] = -rsum[pos.first];
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
