#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    string s, t;
    cin >> s >> t;
    vector<int> scnt(26, 0), tcnt(26, 0);
    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (i - k < 0 && i + k >= n) {
            possible &= s[i] == t[i];
        } else {
            scnt[s[i] - 'a']++;
            tcnt[t[i] - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        possible &= scnt[i] == tcnt[i];
    }
    possible ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
