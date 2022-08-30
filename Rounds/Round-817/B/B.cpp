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
    string s1, s2;
    cin >> s1 >> s2;
    bool same = true;
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            if ((s1[i] == 'G' && s2[i] == 'B') ||
                (s1[i] == 'B' && s2[i] == 'G'))
                continue;
            same = false;
        }
    }
    same ? printf("YES\n") : printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
