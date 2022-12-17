#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int perform_swap(int f, int s, vector<vector<int>>& a) {
    int col = 0;
    while (!(a[f][col] == 1 && a[s][col] == 0)) col++;
    swap(a[f][col], a[s][col]);
    return col;
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<vector<int>> a(n, vector<int>(m));
    vector<pair<int, int>> sum(n, {0, 0});
    int tot = 0;
    for (int i = 0; i < n; i++) {
        sum[i].second = i;
        for (int j = 0; j < m; j++) {
            scanf("%lld", &a[i][j]);
            sum[i].first += a[i][j];
            tot += a[i][j];
        }
    }
    if (tot % n != 0) {
        printf("-1\n");
        return;
    }
    vector<vector<int>> ans;
    sort(sum.begin(), sum.end());
    int val = tot / n;
    int s = 0, e = n - 1;
    while (s < e) {
        while (sum[s].first == val) s++;
        while (sum[e].first == val) e--;
        if (s >= e) break;
        // swap them
        sum[s].first++;
        sum[e].first--;
        int index = perform_swap(sum[e].second, sum[s].second, a);
        ans.push_back({sum[e].second + 1, sum[s].second + 1, index + 1});
    }
    printf("%lld\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%lld %lld %lld\n", ans[i][0], ans[i][1], ans[i][2]);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
