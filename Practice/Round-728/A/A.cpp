#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;

    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> a(n);
        iota (a.begin(), a.end(), 1);

        for (int i = 1; i < n; i += 2) {
            swap (a[i], a[i-1]);
        }

        if (n % 2 == 1) {
            swap (a[n-1], a[n-3]);
        }

        for (int i = 0; i < n; i++) {
            printf("%lld ", a[i]);
        }
        printf("\n");
    }
}
