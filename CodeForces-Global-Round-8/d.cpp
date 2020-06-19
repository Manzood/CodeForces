#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
 
int main() {
	int n;
	scanf("%d",&n);
	vector <long long> a(n);
	long long m=0;
	int ind=0;
	for (int i=0;i<n;i++) {
		scanf("%lld",&a[i]);
		if (a[i]>m) {
			ind=i;
		}
	}
	sort(a.begin(),a.end());
	for (int i=0;i<n-1;i++) {
		int index=n-1;
		while (index>i) {
			if (a[index]|a[i]>a[index]) {
				long long temp=a[index];
				a[index]|=a[i];
				a[i]&=temp;
			}
			index--;
		}
	}
	long long ans=0;
	for (int i=0;i<n;i++) {
		ans+=(a[i]*a[i]);
	}
	cout<<ans<<endl;
}	