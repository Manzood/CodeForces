#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e17;

int getval(int a, int b, int c) {
    vector<int> x = {a, b, c};
    sort(x.begin(), x.end());
    int ret = 0;
    for (auto cur : x) ret += abs(cur - x[1]);
    return ret;
}

int getbest(vector<int>& a) {
    int n = (int)a.size();
    int ret = 0;
    vector<int> dp(n, INF);
    dp[n - 2] = abs(a[n - 1] - a[n - 2]);
    for (int i = n - 3; i >= 0; i--) {
        dp[i] = dp[i + 2] + abs(a[i] - a[i + 1]);
        if (i < n - 3) {
            dp[i] = min(dp[i], dp[i + 3] + getval(a[i], a[i + 1], a[i + 2]));
        } else {
            dp[i] = min(dp[i], getval(a[i], a[i + 1], a[i + 2]));
        }
    }

    return dp[0];
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    int ans = getbest(a);
    vector<int> b, c;
    for (int i = 1; i < n; i++) b.push_back(a[i]);
    b.push_back(a[0]);
    for (int i = 2; i < n; i++) c.push_back(a[i]);
    c.push_back(a[0]);
    c.push_back(a[1]);
    ans = min(ans, getbest(b));
    ans = min(ans, getbest(c));

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
