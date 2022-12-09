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
    int n = (int)s.size();
    string yes = "Yes";
    int ind = 0;
    bool ans = true;
    while (ind < 3 && s[0] != yes[ind]) ind++;
    if (ind >= 3) {
        ans = false;
    } else {
        for (int i = 1; i < n; i++) {
            ind = (ind + 1) % 3;
            if (s[i] != yes[ind]) ans = false;
        }
    }
    ans ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
