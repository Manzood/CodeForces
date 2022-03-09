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
    char c;
    cin >> s;
    cin >> c;
    bool possible = false;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == c) {
            if (i % 2 == 0) {
                possible = true;
            }
        }
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
