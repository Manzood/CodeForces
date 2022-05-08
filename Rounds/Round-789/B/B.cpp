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
    int len = 1;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i-1]) {
            // evaluate
            if (len & 1) {
                if (len == 1) {
                    if (i == 1 && n > 2 && (s[i+1] != s[i] || (n > 3 && s[i+2] != s[i] && s[i+1] == s[i]))) {
                        s[i] = s[i-1];
                    } else {
                        s[i-1] = s[i];
                    }
                } else {
                    s[i] = s[i-1];
                }
                len++;
                ans++;
            } else {
                len = 1;
            }
        } else {
            len++;
        }
    }
    // cout << s << endl;
    int segments = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i-1]) segments++;
    }
    printf("%lld %lld\n", ans, segments);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
