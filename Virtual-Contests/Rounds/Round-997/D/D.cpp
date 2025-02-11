#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int ans = 0;
    for (int x = 1; x <= 10; x++) {
        map<int, int> sums;
        int cur = 0;
        vector<int> tmp = {0};
        for (int i = 0; i < n; i++) {
            if (a[i] < x)
                cur++;
            else
                cur--;
            if (a[i] == x) {
                for (auto val : tmp) sums[val]++;
                tmp = {cur};
                ans += sums[cur];
            } else {
                ans += sums[cur];
                tmp.push_back(cur);
            }
        }
    }
    ans = (n * (n + 1) / 2) - ans;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
