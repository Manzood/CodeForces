#include "bits/stdc++.h"
#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif
using namespace std;
#define int long long

void solve() {
    int n, k;
    scanf("%lld%lld", &n, &k);
    string s;
    cin >> s;
    map <char, int> cnt;
    for (auto c: s) {
        cnt[c]++;
    }
    int pairs = 0, singles = 0;
    for (auto x: cnt) {
        pairs += x.second / 2;
        singles += x.second % 2;
    }
    // debug (s, pairs);
    int ans = 2 * (pairs / k) + (2 * (pairs % k) + singles >= k);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
