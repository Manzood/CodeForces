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
    int ones = 0, zeroes = 0;
    for (int i = 0; i < n; i++) {
        ones += s[i] == '1';
        zeroes += s[i] == '0';
    }

    bool possible = true;
    int req = n / 2 - k;
    if (ones < req || zeroes < req) possible = false;
    ones -= req, zeroes -= req;
    if ((ones & 1) || (zeroes & 1)) possible = false;

    printf(possible ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
