#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    string s;
    cin >> s;
    if (n > 2) {
        printf("NO\n");
    } else {
        if (n == 2) {
            if (s[0] == s[1]) {
                printf("NO\n");
            } else {
                printf("YES\n");
            }
        } else {
            printf("YES\n");
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
