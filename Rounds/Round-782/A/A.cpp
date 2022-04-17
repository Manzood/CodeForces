#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, r, b;
    scanf("%lld%lld%lld", &n, &r, &b);
    int val = r / (b + 1) + (r % (b + 1) > 0);
    int num = r % (b + 1);
    int len = 0;
    int rcount = 0;
    int cur = 0;
    for (int i = 0; i < b; i++) {
        if (cur == num && num > 0) {
            val--;
        }
        for (int j = 0; j < val && rcount < r; j++) {
            printf("R");
            len++;
            rcount++;
        }
        cur++;
        printf("B");
        len++;
    }
    while (len < n) {
        printf("R");
        len++;
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
