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
    int a = n / 2;
    int b = a;
    bool odd = true;
    if (n & 1) {
        b++;
        int mult = 1;
        do {
            mult *= 10;
            if ((a % mult) / (mult / 10) == 9) {
                if (odd) {
                    a -= 4 * (mult / 10);
                    b += 4 * (mult / 10);
                } else {
                    a -= 5 * (mult / 10);
                    b += 5 * (mult / 10);
                }
            } else {
                break;
            }
            odd ^= true;
        } while (mult <= a);
    }
    printf("%lld %lld\n", a, b);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
