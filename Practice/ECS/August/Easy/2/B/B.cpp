#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    string t;
    cin >> t;
    string a;

    int n = (int)t.size();
    for (int i = 0; i < n; i++) {
        if (t[i] != 'a') a += t[i];
    }

    bool possible = true;
    int m = (int)a.size();
    if (a.substr(0, m / 2) != a.substr(m / 2, m)) possible = false;

    a = a.substr(0, m / 2);
    m /= 2;
    if (t.substr(n - m, n) != a) possible = false;

    string s;
    s = t.substr(0, n - m);

    if (!possible) {
        cout << ":(" << "\n";
    } else {
        cout << s << "\n";
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
