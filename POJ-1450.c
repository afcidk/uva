#include<stdio.h>

int main() {
	int n, count = 0;
	scanf("%d", &n);
	while(n--){
		int a,b;
		scanf("%d%d", &a, &b);
		if(a*b%2 == 1){
			printf("Scenario #%d:\n%d.41\n\n", ++count, a*b);
		}
		else{
			printf("Scenario #%d:\n%d.00\n\n", ++count, a*b);
		}
	}
}
