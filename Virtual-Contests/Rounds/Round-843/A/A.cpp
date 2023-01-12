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
    int a_ind = -1;
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == 'a') a_ind = i;
    }
    if (a_ind > -1) {
        cout << s.substr(0, a_ind) << " a "
             << s.substr(a_ind + 1, n - a_ind - 1);
    } else {
        cout << s[0] << " " << s.substr(1, n - 2) << " " << s[n - 1];
    }
    cout << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
