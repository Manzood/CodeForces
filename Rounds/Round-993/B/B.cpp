#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    string a;
    cin >> a;
    reverse(a.begin(), a.end());
    int n = (int)a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] == 'p') {
            a[i] = 'q';
        } else if (a[i] == 'q') {
            a[i] = 'p';
        }
    }
    cout << a << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
