#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        int n, d, m;
        scanf("%d%d%d", &n, &d, &m);
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a.begin(), a.end());
        int first = 0, last = n-1;
        long long ans = 0;
        while (first <= last) { 
            if (a[last] > m && (first + d < last || a[first] > m)) {
                first += d;
                ans += a[last];
                last--;
            }
            else {
                ans += a[first];
                first++;
            }
        }
        printf("%lld\n", ans);
    }
}