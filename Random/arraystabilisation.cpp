#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int temporary = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    temporary++;
    sort(a.begin(), a.end());
    printf("%d", min(a[n - 1] - a[1], a[n - 2] - a[0]));
}
