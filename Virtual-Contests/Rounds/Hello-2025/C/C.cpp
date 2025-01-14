#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void printBitwise(int n) {
    bitset<8> b = n;
    debug(b);
}

void temp() {
    printBitwise(48), printBitwise(47), printBitwise(41);
    debug("here");
    printBitwise(48), printBitwise(50), printBitwise(41);
}

void solve([[maybe_unused]] int test) {
    int l, r;
    scanf("%lld%lld", &l, &r);
    int bit = 30;
    int val = 0;
    while (bit >= 0) {
        val += (1LL << bit) & r;
        if (((1LL << bit) & r) != ((1LL << bit) & l)) {
            break;
        }
        bit--;
    }
    int cur = l;
    while (cur == val || cur == val - 1) cur++;
    printf("%lld %lld %lld\n", val, val - 1, cur);
}

int32_t main() {
    int t = 1;
    cin >> t;
    // temp();
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
