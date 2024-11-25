#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int n;
	cin>>n;
	vector <int> a(n);
	int neg=-1;
	int pos=-1;
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
		if (a[i]<0) 
			neg=i;
		else
			pos=i;
	}
	//create positive or negative
	if (neg==-1 || pos==-1)
		sort(a.begin(),a.end());
	if (neg==-1) {
		int m;
		for (int i=0;i<n;i++) {
			if (i==0) m=a[i+1]-a[i];
			else {
				if (m>a[i+1]-a[i]) {
					m=a[i+1]-a[i];
					neg=i;
				}
			}
		}
	}
	//write a case for pos being negative here
	for (int i=0;i<n;i++) {
		if (a[i]>0 && i!=pos) {
			a[neg]-=a[i];
			a[i]=0;
		}
	}
	for (int i=0;i<n;i++) {
		if (a[i]<0) {
			a[pos]-=a[i];
			a[i]=0;
		}
	}

