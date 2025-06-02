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
    int sum = 1;
    bool possible = false;
    for (int i = 1; i < n - 1; i++) {
        sum += (s[i] == '(' ? 1 : -1);
        if (sum == 0) possible = true;
    }
    printf(possible ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
