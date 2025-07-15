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

    if (n < 2 * k) {
        printf("Alice\n");
        return;
    }

    int ones = count(s.begin(), s.end(), '1');
    if (ones > k) {
        printf("Bob\n");
    } else {
        printf("Alice\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
