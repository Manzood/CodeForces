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
    map<int, int> last;

    int target = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a')
            target--;
        else
            target++;
    }

    int cur = 0;
    last[0] = -1;
    int ans = n;
    if (target == 0) ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a')
            cur--;
        else
            cur++;

        if (last.count(cur - target)) {
            ans = min(ans, i - last[cur - target]);
        }
        last[cur] = i;
    }
    if (ans == n) ans = -1;

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
