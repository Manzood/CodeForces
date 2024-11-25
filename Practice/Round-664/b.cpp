#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        int n, m, x, y;
        scanf("%d%d%d%d", &n, &m, &x, &y);
        // current row
        for (int i = x; i > 0; i--) {
            printf("%d %d\n", i, y);
        }
        for (int i = x+1; i <= n; i++) {
            printf("%d %d\n", i, y);
        }
        int curr = n;
        for (int j = y-1; j > 0; j--) {
            printf("%d %d\n", curr, j);
            if (curr == n) {
                for (int i = curr-1; i > 0; i--) {
                    printf("%d %d\n", i, j);
                }
                curr = 1;
            }
            else {
                for (int i = 2; i <= n; i++) {
                    printf("%d %d\n", i, j);
                }
                curr = n;
            }
        }
        for (int j = y+1; j <= m; j++) {
            printf("%d %d\n", curr, j);
            if (curr == n) {
                for (int i = curr-1; i > 0; i--) {
                    printf("%d %d\n", i, j);
                }
                curr = 1;
            }
            else {
                for (int i = 2; i <= n; i++) {
                    printf("%d %d\n", i, j);
                }
                curr = n;
            }
        }
    }
}