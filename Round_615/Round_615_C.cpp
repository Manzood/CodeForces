#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n;
		long long a=0,b=0,c=0;
		scanf("%lld",&n);
		long long m=n;
		long long factor=2;
		bool flag=0;
		while (n>1&&(a==0||b==0||c==0)&&factor<=(n/2))
		{
			if (a==0 && factor>=sqrt(n))
				break;
			if (n%factor==0)
			{
				if (a==0)
				{
					a=factor;
					n=n/factor;
				}
				else if (b==0 && factor!=(n/factor) && (n/factor)!=a && factor!=a)
				{
					b=factor;
					c=n/factor;
					n=1;
					flag=1;
				}
			}
			factor++;
		}
		if (flag && (a!=b) && (b!=c) && (a*b*c)==m)
		{
			printf("YES\n%lld% lld %lld\n",a,b,c);
		}
		else
		{
			printf("NO\n");
		}
	}
}