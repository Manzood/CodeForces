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
    int cards = n;
    int sub = 2;
    cards--;
    int alice = 1, bob = 0;
    int aliceblack = 0, bobblack = 0;
    int color = 0;
    int cnt = 0;
    bool a = false;
    while (cards > 0) {
        sub = min(cards, sub);
        cards -= sub;
        if (a) {
            alice += sub / 2;
            aliceblack += sub / 2;
            if (sub & 1) {
                if (color)
                    alice++;
                else
                    aliceblack++;
            }
            sub++;
        } else {
            bob += sub / 2;
            bobblack += sub / 2;
            if (sub & 1) {
                if (color)
                    bob++;
                else
                    bobblack++;
            }
            sub++;
        }
        color = (color + sub - 1) % 2;
        cnt++;
        if (cnt % 2 == 0) {
            a ^= true;
        }
    }
    printf("%lld %lld %lld %lld\n", alice, aliceblack, bob, bobblack);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
