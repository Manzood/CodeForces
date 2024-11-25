#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    string s;
    cin >> s;
    int mx = m;
    bool swimming = false, ans = true;
    for (int i = 0; i < n; i++) {
        if (i + 1 >= mx) {
            swimming = true;
        } else {
            swimming = false;
        }
        if (swimming) {
            if (s[i] == 'C')
                ans = false;
            else if (s[i] == 'L') {
                mx = i + m + 1;
            } else {
                k--;
            }
        } else {
            if (s[i] == 'L') {
                mx = i + m + 1;
            }
        }
    }
    if (k < 0) ans = false;
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
