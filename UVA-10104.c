#include<stdio.h>
#define swap(a, b) {int t;t=a;a=b;b=t;}

int exGcd(int, int, int*, int*);

int main() {
	int a, b;
	while(scanf("%d%d", &a, &b) == 2){
		int X=1, Y=0;
		int gcd = exGcd(a, b, &X, &Y);
		printf("%d %d %d\n", X, Y, gcd);
	}
	return 0;
}

int exGcd(int a, int b, int *X, int *Y){
	if(b == 0){
		*X = 1;
		*Y = 0;
		return a;
	}
	else{
		int gcd = exGcd(b, a%b, X, Y);
		int tx = *X;
		int ty = *Y;
		*X = ty;
		*Y = tx-(a/b)*ty;
		return gcd;
	}
}
