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
    for (int i = 1; i < 100; i++) {
        if (i % 3 == 0) s += 'F';
        if (i % 5 == 0) s += 'B';
    }
    string t;
    cin >> t;
    bool ans = false;
    for (int i = 0; i + n <= (int)s.size(); i++) {
        bool found = true;
        for (int j = 0; j < n; j++) {
            found &= (s[i + j] == t[j]);
        }
        ans |= found;
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
