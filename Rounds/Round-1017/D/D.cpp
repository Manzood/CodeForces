#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    string a, b;
    cin >> a >> b;
    int n = (int)a.size(), m = (int)b.size();
    int x = 1, y = 1, f = 0, s = 0;
    bool possible = true;
    while (f < n) {
        while (f < n - 1 && a[f + 1] == a[f]) {
            f++;
            x++;
        }
        while (s < m - 1 && b[s + 1] == b[s]) {
            s++;
            y++;
        }
        if (x > y || x * 2 < y || a[f] != b[s]) possible = false;
        x = 1;
        y = 1;
        f++;
        s++;
    }
    if (s < m) possible = false;
    printf(possible ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
