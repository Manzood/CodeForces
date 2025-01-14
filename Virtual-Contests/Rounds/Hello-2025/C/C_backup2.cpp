#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int getVal(int a, int b, int c) { return (a ^ b) + (b ^ c) + (a ^ c); }

void solve([[maybe_unused]] int test) {
    int l, r;
    scanf("%lld%lld", &l, &r);
    int a = l, b = 0, x = 0, c = r;
    bool found = false, found2 = false;
    for (int i = 30; i >= 0; i--) {
        if (!found) {
            if (((1LL << i) & l) != ((1LL << i) & r)) {
                found = true;
                b += (1LL << i);
                continue;
            } else {
                b += (1LL << i) & l;
            }
        }
        if (found) {
            if (!found2) {
                if ((1LL << i) & r) {
                    found2 = true;
                }
            } else {
                b += ((1LL << i) & l) ^ (1LL << i);
            }
        }
    }
    found = false, found2 = false;
    for (int i = 30; i >= 0; i--) {
        if (!found) {
            if (((1LL << i) & l) != ((1LL << i) & r)) {
                found = true;
                continue;
            } else {
                x += (1LL << i) & l;
            }
        }
        if (found) {
            if (!found2) {
                x += (1LL << i);
                if (!((1LL << i) & l)) {
                    found2 = true;
                }
            } else {
                x += ((1LL << i) & l) ^ (1LL << i);
            }
        }
    }
    if ((a ^ x) + (c ^ x) > (a ^ b) + (c ^ b)) b = x;
    if (b == a || b == c) b = x;
    assert(a < b && b < c);
    printf("%lld %lld %lld\n", a, b, c);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
