#include<cstdio>
#include<iostream>
using namespace std;

int main() {
	long long int a, b;
	/*straight lines + slanting lines*/
	while(scanf("%lld%lld", &a, &b)==2 && (a||b)){
		long long int ans=a*b*(a+b-2), slant=0;
		long long int i, j;
		long long int mi=min(a,b), ma=max(a,b);

		slant+=(mi-1)*mi*(mi*2-4)/3;// /3=*2/6
		slant+=(mi-1)*mi*(ma-mi+1);
		slant*=2;
		ans+=slant;
		printf("%lld\n", ans);
	}
	return 0;
}
