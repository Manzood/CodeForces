#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int num;
    scanf("%lld", &num);
    if (num % 7 == 0) {
        printf("%lld\n", num);
    } else {
        num -= num % 10;
        for (int i = 0; i < 10; i++) {
            if ((num + i) % 7 == 0) {
                printf("%lld\n", num + i);
                break;
            }
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
