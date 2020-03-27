#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

#define debug(x) cout<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		scanf("%d",&n);
		vector <int> colours(n);
		int current,previous;
		scanf("%d",&previous);
		int col=1;
		int first=previous;
		colours[0]=col;
		int k=1;
		for (int i=1;i<n;i++) {
			scanf("%d",&current);
			if (current!=previous && i<n-1) {
				k=2;
				if (col==1)
					col=2;
				else
					col=1;
				colours[i]=col;
			}
			else if (i==n-1) {
				//debug(first);
				//debug(previous);
				if (first!=previous && current!=previous) {
					k=3;
					colours[i]=3;
				}
				else if (k==2) {
					if (current!=previous) {
						if (col==1)
							colours[i]=2;
						else
							colours[i]=1;
					}
					else {
						colours[i]=col;
					}
				}
				else 
					colours[i]=col;
			}
			else {
				colours[i]=col;
			}
			previous=current;
		}
		printf("%d\n",k);
		for (int i=0;i<n;i++) {
			printf("%d ",colours[i]);
		}
		printf("\n");
	}
}