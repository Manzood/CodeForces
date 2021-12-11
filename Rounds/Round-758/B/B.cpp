#include "bits/stdc++.h"

#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif

using namespace std;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        scanf("%lld %lld %lld", &n, &a, &b);
        vector <int> A(n);
        iota (A.begin(), A.end(), 1LL);
        if (a + b > n - 2 || abs (a - b) > 1) {
            printf("-1\n");
            continue;
        }

        // create minimas;
        // swap (a, b);
        // bool swapped = false;
        // if (a > b) {
        //     swap (a, b);
        //     swapped = true;
        // }

        if (b > a) {
            int cntb = 0, cnta = 0;
            while (cntb < b) {
                int ind = cntb * 2 + 1;
                // debug (b, ind);
                swap (A[ind], A[ind-1]);
                cntb++;
                if (cntb > 1) cnta++;
            }

            for (int i = n - 1; i >= 0 && cnta < a; i -= 2) {
                swap (A[i], A[i-1]);
                cnta++;
            }
        } else {
            int cntb = 0, cnta = 0;
            for (int i = n - 1; i >= 0 && cnta < a; i -= 2) {
                swap (A[i], A[i-1]);
                cnta++;
                if (cnta > 1) {
                    cntb++;
                }
            }

            if (cntb < b) {
                swap (A[0], A[1]);
                cntb++;
            }
        }

        // if (swapped) {
        //     for (int i = 1; i < n; i += 2) {
        //         swap (A[i], A[i-1]);
        //     }
        // }

        for (int i = 0; i < n; i++) {
            printf("%lld ", A[i]);
        }
        printf("\n");
    }
}
