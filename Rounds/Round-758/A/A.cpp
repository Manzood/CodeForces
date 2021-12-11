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
        int n;
        scanf("%lld", &n);
        vector <int> a;
        a.push_back (2);
        for (int i = 0; i < n - 1; i++) {
            int val = a[i] + 1;
            while (val % a[i] == 0) val++;
            a.push_back (val);
        }
        for (int i = 0; i < n; i++) {
            printf("%lld ", a[i]);
        }
        printf("\n");
    }
}
