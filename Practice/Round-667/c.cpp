#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        int val = 0;
        for (int i = n-1; i >= 1; i--) {
            if ((y-x) % i == 0) {
                val = i;
                break;
            }
        }
        int current = x;
        int found = false;
        int diff = (y-x)/val;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            printf("%d ", current);
            mx = max(current, mx);
            if (current == y && x - diff > 0) {
                found = true;
                current = x;
            }
            if (!found)
                current += diff;
            else if (current - diff > 0)
                current -= diff;
            else {
                current = mx + diff;
                found = false;
            }
        }
        printf("\n");
    }
}