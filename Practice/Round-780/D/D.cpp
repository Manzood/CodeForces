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
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int numtwos = 0;
    int firstind = 0;
    int secondind = -1;
    int sign = 0;
    int mx = 0;
    bool foundneg = false;
    int firstneg = -1;
    int foundbefore = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            numtwos = 0;
            foundbefore = 0;
            firstind = i + 1;
            foundneg = false;
            sign = 0;
        } else if (a[i] == -1) {
            if (!foundneg) {
                firstneg = i;
                foundneg = true;
            }
            sign ^= 1;
        } else if (a[i] == -2) {
            if (!foundneg) {
                firstneg = i;
                foundbefore++;
                foundneg = true;
            }
            sign ^= 1;
            numtwos++;
        } else if (a[i] == 2) {
            foundbefore++;
            numtwos++;
        }
        if (sign == 0 && mx < numtwos) {
            secondind = i;
            mx = numtwos;
        } else if (sign == 1) {
            if (numtwos - foundbefore > mx) {
                secondind = i;
                firstind = firstneg + 1;
                mx = numtwos - foundbefore;
            }
            // if (test == 5) debug(i, mx, numtwos, foundbefore);
        }
    }
    // if (test == 5) debug(firstind, secondind, n);
    printf("%lld %lld\n", firstind, n - secondind - 1);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
