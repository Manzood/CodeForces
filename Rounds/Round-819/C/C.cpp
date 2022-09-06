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
    string s;
    cin >> s;
    int level = 0;
    int ans = 1;
    vector<int> discovered(n, false);
    discovered[0] = true;
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == '(') {
            // discovered[level] = false;
            level++;
            discovered[level] = true;
            if (level > 1 && discovered[level - 2] == true) {
                ans++;
                discovered[level - 2] = false;
            }
        } else {
            level--;
            discovered[level] = true;
        }
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
