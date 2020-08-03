#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (2*l <= r) {
            printf("%d %d\n", l, 2*l);
        }
        else {
            printf("-1 -1\n");
        }
    }
}