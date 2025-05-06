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
    cin >> s;

    bool hasone = s[0] == 'A', hasn = s[n - 1] == 'A';
    bool alice = false;
    int bobcount = 0;
    for (int i = 0; i < n; i++) {
        bobcount += s[i] == 'B';
    }

    if (hasone && hasn) {
        alice = true;
    } else if (hasone) {
        if (bobcount == 1) alice = true;
    } else if (hasn) {
        if (s[n - 2] == 'A') alice = true;
    }

    printf(alice ? "Alice\n" : "Bob\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
