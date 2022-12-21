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
    int p;
    scanf("%lld", &p);
    vector<int> components;
    int tot = 0, uni = 0;
    vector<int> dp(p + 1, INF);
    vector<int> prev(p + 1, 0);
    vector<int> c, moves;
    int val = 1, add = 2;
    map<int, int> mp;
    while (val <= p) {
        c.push_back(val);
        moves.push_back(add);
        mp[c.back()] = add;
        val += add;
        add++;
    }
    dp[0] = 0;
    for (int i = 0; i < (int)c.size(); i++) {
        for (int j = c[i]; j <= p; j++) {
            if (dp[j - c[i]] + moves[i] < dp[j]) {
                prev[j] = c[i];
            }
            dp[j] = min(dp[j], dp[j - c[i]] + moves[i]);
        }
    }
    while (p > 0) {
        components.push_back(mp[prev[p]]);
        p -= prev[p];
    }
    for (auto x : components) {
        tot += x;
    }
    for (auto x : components) {
        uni += x * (tot - x);
    }
    uni /= 2;
    printf("%lld %lld\n", tot, uni);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
