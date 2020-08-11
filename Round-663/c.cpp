#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()
const int MOD = 1e9+7;

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        long long ans = 1;
        for (int i = 4; i <= n; i++) {
            if (i == 4) ans = 16;
            else {
                ans *= 2LL;
                ans %= MOD;
            }
        }
        printf("%lld\n", ans);
    }
}