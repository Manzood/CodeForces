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
    int ans = 0;
    vector<int> marked(n, false);
    for (int i = 0; i < n; i++) {
        int val = i + 1;
        if (s[i] == '0') {
            if (!marked[i]) {
                ans += val;
            }
            for (int j = 2 * val; j <= n; j += val) {
                int cur = j - 1;
                if (s[cur] == '0' && !marked[cur]) {
                    marked[cur] = true;
                    ans += val;
                } else if (s[cur] == '1') {
                    break;
                }
            }
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
