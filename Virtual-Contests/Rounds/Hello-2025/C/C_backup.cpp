#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int l, r;
    scanf("%lld%lld", &l, &r);
    int a = l, b = 0, x = 0, c = r;
    bool found = false, other = false, temp = false, other2 = false;
    for (int i = 30; i >= 0; i--) {
        if (!found) {
            if ((r & (1LL << i)) != (l & (1LL << i))) {
                found = true;
                if (i > 0) {
                    i--;
                    int f = ((1LL << i) & r) > 0;
                    int s = ((1LL << i) & l) > 0;
                    if (f == 0 && s == 0) {
                        b += (1LL << i);
                    } else if (f == 1 && s == 1) {
                        b += (1LL << (i + 1));
                    } else if (f == 1 && s == 0) {
                        b += (1LL << i);
                    } else {
                        x = b;
                        x += (1LL << (i + 1));
                        b += (1LL << (i + 1));
                        other = true;
                        temp = true;
                    }
                }
                continue;
            } else {
                b += (l & (1LL << i));
            }
        }
        if (found) {
            if (temp) {
                if (other2) {
                    if (!((1LL << i) & l)) {
                        other2 = false;
                        x += (l & (1LL << i)) ^ (1LL << i);
                    } else {
                        x += (1LL << i);
                    }
                } else {
                    x += (l & (1LL << i)) ^ (1LL << i);
                }
            }
            if (other) {
                if ((1LL << i) & r) {
                    other = false;
                }
            } else {
                b += (l & (1LL << i)) ^ (1LL << i);
            }
        }
    }
    // if (test == 6) debug((98 ^ 85) + (98 ^ 76) + (85 ^ 76));
    // if (test == 6) debug((98 ^ 90) + (98 ^ 69) + (90 ^ 69));
    assert(a <= b && b <= c);
    if (temp) assert(a <= x && x <= c);
    if (temp && (a ^ x) + (c ^ x) > (a ^ b) + (c ^ b)) {
        b = x;
    }
    printf("%lld %lld %lld\n", a, b, c);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}

// 3 + 2 + 1
// 55 + 46 + 25
// 3 + 39 + 36
// 01100010
// 01011101
// 01000100
// 01000101

// sample:
// 01100010
// 01010101
// 01001100
// 00222222

// old:
// 01100010
// 01100000
// 01000101
// 00200222

// target:
// 01100010
// 01
// 01000101
