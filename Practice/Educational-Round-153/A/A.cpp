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
    string a, b;
    for (int i = 0; i < n; i++) a += '(';
    for (int i = 0; i < n; i++) a += ')';
    for (int i = 0; i < n; i++) b += "()";
    bool found_a = false, found_b = false;
    for (int i = 0; i <= n; i++)
        if (a.substr(i, n) == s) found_a = true;
    for (int i = 0; i <= n; i++) {
        if (b.substr(i, n) == s) found_b = true;
    }
    bool ans = !(found_a && found_b);
    ans ? printf("YES\n") : printf("NO\n");
    if (ans) {
        if (found_a)
            cout << b << "\n";
        else
            cout << a << "\n";
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
