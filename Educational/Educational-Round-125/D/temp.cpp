#include "bits/stdc++.h"
#include "custom/debugger.h"
using namespace std;

int32_t main() {
    int m = (int) 1e6;
    int ops = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; i * j <= m; j++) {
            // debug (i, j, ops);
            ops++;
        }
    }
    printf("%d\n", ops);
}
