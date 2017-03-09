#include<stdio.h>
#define swap(a,b) {int t;t=a;a=b;b=t;}

int main() {
	int a, b;
	while(scanf("%d%d", &a, &b)==2){
		int i;
		printf("%d %d ", a, b);
		if(a>b)	swap(a, b);
		int ma = 0;
		for(i = a; i<=b; i++){
			int temp = i;
			int count = 1;
			while(temp!=1){
				if(temp % 2 == 0)	temp/=2;
				else temp = temp*3+1;
				count++;
			}
			if(ma < count)	ma = count;
		}
		printf("%d\n", ma);
	}
	return 0;
}
