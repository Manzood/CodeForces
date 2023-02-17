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
    int x = 0, y = 0;
    bool ans = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') {
            y++;
        } else if (s[i] == 'D') {
            y--;
        } else if (s[i] == 'L') {
            x--;
        } else {
            x++;
        }
        if (x == 1 && y == 1) {
            ans = true;
        }
    }
    printf(ans ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
