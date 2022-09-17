#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    cout << "1\n";
    cout << "200000\n";
    int val = (int)1e9 - (int)4e5;
    // debug(val);
    for (int i = 0; i < (int)2e5; i++) {
        cout << val++ << " \n"[i == (int)2e5 - 1];
    }
    for (int i = 0; i < (int)2e5; i++) {
        cout << val++ << " \n"[i == (int)2e5 - 1];
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
