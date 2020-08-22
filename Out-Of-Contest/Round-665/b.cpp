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
        a -= min(a, z);
        z -= min(a, z);
        ans += min(c, y) * 2;
        c -= min(c, y);
        y -= min(c, y);
        b -= min(b, x);
        x -= min(b, x);
        ans -= 2 * min(z, b);
        printf("%lld\n", ans);
    }
}