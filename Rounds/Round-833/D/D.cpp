#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int gcdExtended(int a, int b, int* x, int* y) {
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int modInverse(int A, int M) {
    int x, y;
    int g = gcdExtended(A, M, &x, &y);
    if (g != 1)
        return -1;
    else {
        int res = (x % M + M) % M;
        return res;
    }
}

void solve([[maybe_unused]] int test) {
    int a, b, d;
    scanf("%lld%lld%lld", &a, &b, &d);
    bool possible = true;
    int k = 0;
    while (!((1LL << k) & d)) k++;
    int j = 0;
    while (!((1LL << j) & a)) j++;
    possible &= j >= k;
    j = 0;
    while (!((1LL << j) & b)) j++;
    possible &= j >= k;
    int p = (1LL << 30) / (1LL << k);
    p = modInverse(p, d >> k) - 1;
    if (p < 0) p += d >> k;
    p <<= 30;
    int x = p + (1LL << 30) - (1LL << k);
    printf("%lld\n", possible ? x : -1LL);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
