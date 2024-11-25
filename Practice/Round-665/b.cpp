#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int a, b, c;
        int x, y, z;
        cin >> a >> b >> c >> x >> y >> z;
        long long ans = 0;
        int m = min(a, z);
        a -= m;
        z -= m;
        ans += min(c, y) * 2;
        m = min(c, y);
        c -= m;
        y -= m;
        m = min(b, x);
        b -= m;
        x -= m;
        ans -= 2 * min(z, b);
        printf("%lld\n", ans);
    }
}