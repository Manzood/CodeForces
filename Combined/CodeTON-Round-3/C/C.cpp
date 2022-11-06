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
    string a, b;
    cin >> a >> b;
    bool same = true, diff = true;
    int zeroes = 0;
    for (int i = 0; i < n; i++) {
        same = same & (a[i] == b[i]);
        diff = diff & (a[i] != b[i]);
        zeroes += (a[i] == '0');
    }
    if (!same && !diff) {
        printf("NO\n");
        return;
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        if (a[i] == '0') {
            ans.push_back({i, i});
        }
    }
    if ((zeroes % 2 == 0 && !diff) || (zeroes % 2 == 1 && diff)) {
        ans.push_back({0, 0});
        ans.push_back({1, n - 1});
    } else {
        ans.push_back({0, n - 1});
    }
    printf("YES\n");
    printf("%lld\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%lld %lld\n", ans[i].first + 1, ans[i].second + 1);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
