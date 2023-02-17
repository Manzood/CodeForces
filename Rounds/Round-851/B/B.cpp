#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    int A, B;
    bool found = false;
    while (!found) {
        int a = A = uniform_int_distribution<int>(0, n)(rng);
        int b = B = n - a;
        int s1 = 0, s2 = 0;
        while (a) {
            s1 += a % 10;
            a /= 10;
        }
        while (b) {
            s2 += b % 10;
            b /= 10;
        }
        if (abs(s1 - s2) <= 1) {
            found = true;
        }
    }
    printf("%lld %lld\n", A, B);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
