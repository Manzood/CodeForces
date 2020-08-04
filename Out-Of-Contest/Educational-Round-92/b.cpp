#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    int tests = t;
    while (t--) {
        int n, k, z;
        scanf("%d%d%d", &n, &k, &z);
        vector <int> a(n);
        vector <int> pref(n+1);
        pref[0] = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            pref[i+1] = pref[i] + a[i];
        }
        int ans = 0;
        for (int i = 1; i <= k; i++) {
            int moves = i;
            int sum = pref[i+1];
            int rem = min((k-i), 2*z);
            moves += rem;
            sum += pref[k-moves+i+1] - pref[i+1];
            if (rem % 2 == 1) sum += a[i-1];
            sum += (rem/2) * (a[i] + a[i-1]);
            ans = max(ans, sum);
        }
        printf("%d\n", ans);
    }
}