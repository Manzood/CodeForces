#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        vector <int> a(n);
        int mi;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (i == 0) mi = a[i];
            else mi = min(mi, a[i]);
        }
        int curr = (mi / n) * n;
        int ans = 0;
        while (ans == 0) {
            for (int i = 0; i < n; i++) {
                if (curr >= a[i]) {
                    ans = i + 1;
                    break;
                }
                curr++;
            }
        }
        printf("%d\n", ans);
    }
}