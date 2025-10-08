#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    string s;
    cin >> s;
    int bot = 0, top = 0, other = 0;
    for (int i = 0; i < k; i++) {
        if (s[i] == '0')
            bot++;
        else if (s[i] == '1')
            top++;
        else
            other++;
    }

    string out;
    for (int i = 0; i < n; i++) {
        if (i + 1 <= bot || n - i <= top) {
            out += '-';
        } else if (i + 1 <= bot + other || n - i <= top + other) {
            if (bot + other + top == n)
                out += '-';
            else
                out += '?';
        } else {
            out += '+';
        }
    }

    cout << out << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
