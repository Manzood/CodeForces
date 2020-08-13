#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int a[4];
        int cnt = 0;
        int m = 0;
        for (int i = 0; i < 4; i++) {
            scanf("%d", &a[i]);
            if (a[i] % 2 != 0) {
                cnt++;
            }
            if (i < 3) {
                if (i == 0) m = a[i];
                else m = min (m, a[i]);
            }
        }
        // debug(cnt);
        if (cnt == 2 || (cnt == 3 && m == 0)) 
            printf("No\n");
        else
            printf("Yes\n");
    }
}