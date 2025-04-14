#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    vector<string> a(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    string out = {a[0][0], a[1][0], a[2][0]};
    cout << out << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
