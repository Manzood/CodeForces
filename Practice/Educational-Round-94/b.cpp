#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int p, f, cnts, cntw, s, w;
        cin >> p >> f >> cnts >> cntw >> s >> w;
        if (w < s) {
            swap (w, s);
            swap (cnts, cntw);
        }
        // greedy doesn't work
        int ans = 0;
        for (int i = 0; i <= cnts; i++) {
            int s1 = min(i, p/s);
            int tp = p, tf = f;
            int tempcnts = cnts;
            int tempcntw = cntw;
            tempcnts -= s1;
            int s2 = min((tp - s1*s)/w, tempcntw);
            int f1 = min(tempcnts, tf/s);
            tf -= f1*s;
            int f2 = min(tempcntw - s2, tf/w);
            ans = max(ans, s1 + s2 + f1 + f2);
        }
        printf("%d\n", ans);
    }
}