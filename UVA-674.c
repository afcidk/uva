#include<stdio.h>

const int coins[]={50,25,10,5,1};

int main() {
	int n;
	while(scanf("%d", &n) == 1){
		int p[7500]={1};
		int i, j;
		for(j=0; j<5; ++j){
			for(i=coins[j]; i<=n; ++i){
				p[i]+=p[i-coins[j]];
			}
		}
		printf("%d\n", p[n]);
	}	
	return 0;
}
