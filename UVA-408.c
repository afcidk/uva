#include<stdio.h>
#define swap(a,b) {int t;t=a;a=b;b=t;}

int gcd(int, int);

int main() {
	int a, b;
	while(scanf("%d%d", &a, &b)==2){
		printf("%10d%10d    ", a, b);
		if(a<b)	swap(a, b);
		if(gcd(a,b)==1){
			printf("Good Choice\n\n");
		}
		else printf("Bad Choice\n\n");
	}
	return 0;
}

int gcd(int a, int b){
	if(b == 0)	return a;
	return gcd(b, a%b);
}
