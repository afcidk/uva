#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int GCD(int, int);

int main() {
	int a;
	while(scanf("%d", &a)==1 && a!=0){
		int num[2000];
		num[0]=a;
		int pos=0;
		while(scanf("%d", &a) && a!=0){
			num[++pos]=a;
		}

		int gcd=abs(num[0]-num[1]);
		int i, j, gap;
		for(i=0; i<=pos; ++i){
			for(j=i-1; j>=0; --j){
				gap=abs(num[i]-num[j]);
				gcd=GCD(gap, gcd);
				if(gcd==1)	break;
			}
			if(gcd==1)	break;
		}
		printf("%d\n", gcd);
	}
}

int GCD(int a, int b){
	if(b==0) return a;
	return GCD(b, a%b);
}
