#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        int ans = 0;
        if (n < k) {
            ans = k - n;
        }
        else if (k == 0) {
            if (n & 1) ans = 1;
        }
        printf("%d\n", ans);
    }
}