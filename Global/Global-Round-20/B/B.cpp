#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    string s;
    cin >> s;
    int n = s.size();
    bool possible = true;
    int bcount = 0;
    int acount = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            bcount++;
        } else {
            acount++;
        }
        if (acount < bcount) possible = false;
    }
    if (s[n-1] != 'B') possible = false;
    if (!bcount) possible = false;
    possible ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
