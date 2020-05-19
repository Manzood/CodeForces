#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int n;
	cin>>n;
	vector <int> a(n);
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	sort (a.begin(),a.end());
	printf("%d",min(a[n-1]-a[1],a[n-2]-a[0]));
}